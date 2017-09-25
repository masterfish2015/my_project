/* @flow */

import { createBundleRunner } from './create-bundle-runner'
import type { Renderer, RenderOptions } from './create-renderer'
import { createSourceMapConsumers, rewriteErrorTrace } from './source-map-support'

const fs = require('fs')
const path = require('path')
const PassThrough = require('stream').PassThrough

const INVALID_MSG =
  'Invalid server-rendering bundle format. Should be a string ' +
  'or a bundle Object of type:\n\n' +
`{
  entry: string;
  files: { [filename: string]: string; };
  maps: { [filename: string]: string; };
}\n`

// The render bundle can either be a string (single bundled file)
// or a bundle manifest object generated by vue-ssr-webpack-plugin.
type RenderBundle = {
  basedir?: string;
  entry: string;
  files: { [filename: string]: string; };
  maps: { [filename: string]: string; };
};

export function createBundleRendererCreator (createRenderer: () => Renderer) {
  return function createBundleRenderer (
    bundle: string | RenderBundle,
    rendererOptions?: RenderOptions
  ) {
    const renderer = createRenderer(rendererOptions)

    let files, entry, maps
    let basedir = rendererOptions && rendererOptions.basedir

    // load bundle if given filepath
    if (
      typeof bundle === 'string' &&
      /\.js(on)?$/.test(bundle) &&
      path.isAbsolute(bundle)
    ) {
      if (fs.existsSync(bundle)) {
        const isJSON = /\.json$/.test(bundle)
        basedir = basedir || path.dirname(bundle)
        bundle = fs.readFileSync(bundle, 'utf-8')
        if (isJSON) {
          try {
            bundle = JSON.parse(bundle)
          } catch (e) {
            throw new Error(`Invalid JSON bundle file: ${bundle}`)
          }
        }
      } else {
        throw new Error(`Cannot locate bundle file: ${bundle}`)
      }
    }

    if (typeof bundle === 'object') {
      entry = bundle.entry
      files = bundle.files
      basedir = basedir || bundle.basedir
      maps = createSourceMapConsumers(bundle.maps)
      if (typeof entry !== 'string' || typeof files !== 'object') {
        throw new Error(INVALID_MSG)
      }
    } else if (typeof bundle === 'string') {
      entry = '__vue_ssr_bundle__'
      files = { '__vue_ssr_bundle__': bundle }
      maps = {}
    } else {
      throw new Error(INVALID_MSG)
    }

    const run = createBundleRunner(entry, files, basedir)

    return {
      renderToString: (context?: Object, cb: (err: ?Error, res: ?string) => void) => {
        if (typeof context === 'function') {
          cb = context
          context = {}
        }
        run(context).catch(err => {
          rewriteErrorTrace(err, maps)
          cb(err)
        }).then(app => {
          if (app) {
            renderer.renderToString(app, (err, res) => {
              rewriteErrorTrace(err, maps)
              cb(err, res)
            }, context)
          }
        })
      },

      renderToStream: (context?: Object) => {
        const res = new PassThrough()
        run(context).catch(err => {
          rewriteErrorTrace(err, maps)
          // avoid emitting synchronously before user can
          // attach error listener
          process.nextTick(() => {
            res.emit('error', err)
          })
        }).then(app => {
          if (app) {
            const renderStream = renderer.renderToStream(app, context)

            renderStream.on('error', err => {
              rewriteErrorTrace(err, maps)
              res.emit('error', err)
            })

            // relay HTMLStream special events
            if (rendererOptions && rendererOptions.template) {
              renderStream.on('beforeStart', () => {
                res.emit('beforeStart')
              })
              renderStream.on('beforeEnd', () => {
                res.emit('beforeEnd')
              })
            }

            renderStream.pipe(res)
          }
        })

        return res
      }
    }
  }
}
