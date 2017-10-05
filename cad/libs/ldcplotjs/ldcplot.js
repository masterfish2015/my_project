var ldc_plot = {}
ldc_plot.init = function(option) {
    ldc_plot.target = document.getElementById(option.target_id)
    if (this.target === undefined)
        return

    // create canvas and set width && height
    ldc_plot.canvas = document.createElement('canvas')
    ldc_plot.canvas.width = option.width || 400
    ldc_plot.canvas.height = option.height || 300

    ldc_plot.target.appendChild(this.canvas)
    ldc_plot.target.width = ldc_plot.canvas.width

    ldc_plot.ctx = this.canvas.getContext('2d')

    // draw function graph
    ldc_plot.data = option.data
    if (ldc_plot.data === undefined)
        return

    // range of axis
    ldc_plot.x_axis_range = [0, 10]
    if (option.x_axis && option.x_axis.range) {
        ldc_plot.x_axis_range = option.x_axis.range
    }
    ldc_plot.y_axis_range = [0, 10]
    if (option.y_axis && option.y_axis.range) {
        ldc_plot.y_axis_range = option.y_axis.range
    }
    // label of axis
    ldc_plot.x_label = ''
    if (option.x_axis && option.x_axis.label) {
        ldc_plot.x_label = option.x_axis.label
    }
    ldc_plot.y_label = ''
    if (option.y_axis && option.y_axis.label) {
        ldc_plot.y_label = option.y_axis.label
    }
    // ticks of each axis
    ldc_plot.x_axis_ticks = 10
    if (option.x_axis && option.x_axis.ticks) {
        ldc_plot.x_axis_ticks = option.x_axis.ticks
    }
    ldc_plot.y_axis_ticks = 10
    if (option.y_axis && option.y_axis.ticks) {
        ldc_plot.y_axis_ticks = option.y_axis.ticks
    }
    // type of axis : normal, log
    ldc_plot.x_axis_type = 'normal'
    if (option.x_axis && option.x_axis.type) {
        ldc_plot.x_axis_type = option.x_axis.type
    }
    ldc_plot.y_axis_type = 'normal'
    if (option.y_axis && option.y_axis.type) {
        ldc_plot.y_axis_type = option.y_axis.type
    }

    ldc_plot._draw_x_axis()
    ldc_plot._draw_y_axis()

    // draw dates
    this.data.forEach(function(value, index, array) {
        var type = value.type || 'function'
        var fn = value.fn
        var range = value.range || [0, 10]
        var samples = value.samples || 100
        var step = (range[1] - range[0]) / samples
        var color = value.color || 'black'
        var width = value.width || 1
        var is_first = true
        var title = value.title || 'fun-' + index
        var ctx = ldc_plot.ctx
        var canvas = ldc_plot.canvas

        ctx.beginPath()
        ctx.strokeStyle = color
        ctx.lineWidth = width
        ctx.lineCap = 'round'
        ctx.lineJoin = 'round'

        if (type === 'function') {
            if (ldc_plot.x_axis_type === 'normal') {
                for (var x = range[0]; x < range[1]; x += step) {
                    var y = math.eval(fn, {
                        x: x
                    })
                    var cp = ldc_plot._project(x, y)
                    if (is_first === true) {
                        ctx.moveTo(cp[0], cp[1])
                        is_first = false
                    } else {
                        ctx.lineTo(cp[0], cp[1])
                    }
                }
            } else if (ldc_plot.x_axis_type === 'log') {
                var x0 = math.log(range[0])
                var step = (math.log(range[1] / range[0])) / ldc_plot.x_axis_ticks
                for (var i = 0; i <= ldc_plot.x_axis_ticks; i++) {
                    var x = math.exp(x0 + i * step)
                    var y = math.eval(fn, {
                        x: x
                    })
                    var cp = ldc_plot._project(x, y)
                    if (is_first === true) {
                        ctx.moveTo(cp[0], cp[1])
                        is_first = false
                    } else {
                        ctx.lineTo(cp[0], cp[1])
                    }
                }
            }
        } else if (type === 'points') {
            var points = value.points
            for (var i = 0; i < points.length; i++) {
                var x = points[i][0],
                    y = points[i][1]
                cp = ldc_plot._project(x, y)
                ctx.moveTo(cp[0], cp[1])
                ctx.arc(cp[0], cp[1], width, 0, 2 * Math.PI, true)
                ctx.fillText(points[i][2], cp[0] + 10, cp[1] + 10)
            }
        }

        ctx.stroke()
        var legend_width = ctx.measureText(title).width
        ctx.fillStyle = color
        ctx.fillRect(canvas.width - legend_width, index * 50, legend_width, 20)
        ctx.lineWidth = 1
        ctx.strokeText(title, canvas.width - legend_width, index * 50 + 30)
    })
}

ldc_plot._project = function(x, y) {
    var cx, cy
    var xmin = ldc_plot.x_axis_range[0],
        xmax = ldc_plot.x_axis_range[1],
        ymin = ldc_plot.y_axis_range[0],
        ymax = ldc_plot.y_axis_range[1],
        cw = ldc_plot.canvas.width - 20, // 左右两边留出各10px的空间画刻度或其他
        ch = ldc_plot.canvas.height - 20; // 上下两边留出各10px的空间画刻度或其他
    if (ldc_plot.x_axis_type === 'normal') {
        cx = cw * (x - xmin) / (xmax - xmin) + 10
    } else if (ldc_plot.x_axis_type === 'log') {
        cx = cw * (Math.log(x / xmin)) / (Math.log(xmax / xmin)) + 10
    }
    if (ldc_plot.y_axis_type === 'normal') {
        cy = ch * (ymax - y) / (ymax - ymin) + 10
    } else if (ldc_plot.y_axis_type === 'log') {
        cy = ch * (Math.log(ymax / y)) / (Math.log(ymax / ymin)) + 10
    }

    return [cx, cy]
}

ldc_plot._draw_x_axis = function() {
    var rangex = ldc_plot.x_axis_range, // x轴的显示范围

        rangey = ldc_plot.y_axis_range, // y轴的显示范围

        label = ldc_plot.x_label, // x轴的显示标题

        ticks = ldc_plot.x_axis_ticks, // x轴的刻度（数目）

        type = ldc_plot.x_axis_type, // x轴的类型：normal（笛卡尔坐标），log（对数坐标）

        orgx = 0, // y轴坐标线的位置（x值）

        orgy = (rangey[0] > 0 || rangey[1] < 0) ? rangey[0] : 0 // x轴坐标线的位置（y值）

    // 先画x轴线，注意，缺省下是画在y=0的地方，但是如果ymin > 0 或 ymax <0 则画在 y = ymin的地方
    var cp = []; // 保存canvas下的坐标, x=cp[0], y=cp[1]
    var ctx = ldc_plot.ctx

    ctx.save()
    ctx.beginPath()
    ctx.lineWidth = 5
    ctx.strokeStyle = 'black'
    cp = ldc_plot._project(rangex[0], orgy); // 坐标转换为canvas坐标
    ctx.moveTo(cp[0], cp[1])
    cp = ldc_plot._project(rangex[1], orgy); // 坐标转换为canvas坐标
    ctx.lineTo(cp[0], cp[1])
    ctx.stroke()

    // 再画刻度, 注意
    var step = 0

    if (type === 'normal') {
        step = (rangex[1] - rangex[0]) / ticks
        for (var x = rangex[0]; x <= rangex[1]; x += step) {
            ctx.beginPath()
            ctx.lineWidth = 1
            ctx.strokeStyle = 'grey'

            cp = ldc_plot._project(x, rangey[1]); // 坐标转换为canvas坐标
            ctx.moveTo(cp[0], cp[1])
            cp = ldc_plot._project(x, rangey[0]); // 坐标转换为canvas坐标
            ctx.lineTo(cp[0], cp[1])
            ctx.stroke()

            var tick_label = math.format(x, {
                notation: 'auto',
                precision: 2
            })
            ctx.strokeStyle = 'black'
            ctx.strokeText(tick_label, cp[0] - ctx.measureText(tick_label).width / 2, cp[1] + 10)
        }
    } else if (type === 'log') {
        step = Math.log(rangex[1] / rangex[0]) / ticks
        var x = math.log(rangex[0])

        for (var i = 0; i <= ticks; i++) {
            ctx.beginPath()
            ctx.lineWidth = 1
            ctx.strokeStyle = 'grey'

            var xx = Math.exp(x + i * step)
            cp = ldc_plot._project(xx, rangey[1])
            ctx.moveTo(cp[0], cp[1])
            cp = ldc_plot._project(xx, rangey[0])
            ctx.lineTo(cp[0], cp[1])
            ctx.stroke()

            var tick_label = math.format(xx, {
                notation: 'auto',
                precision: 2
            })
            ctx.strokeStyle = 'black'
            ctx.strokeText(tick_label, cp[0] - ctx.measureText(tick_label).width / 2, cp[1] + 10)
        }
    }
    // //刻度之间的
    ctx.stroke()
    ctx.restore()
}

ldc_plot._draw_y_axis = function() {
    var rangex = ldc_plot.x_axis_range, // x轴的显示范围

        rangey = ldc_plot.y_axis_range, // y轴的显示范围

        label = ldc_plot.y_label, // y轴的显示标题

        ticks = ldc_plot.y_axis_ticks, // y轴的刻度（数目）

        type = ldc_plot.y_axis_type, // y轴的类型：normal（笛卡尔坐标），log（对数坐标）

        orgy = 0, // x轴坐标线的位置（y值）

        orgx = (rangex[0] > 0 || rangex[1] < 0) ? rangex[0] : 0 // y轴坐标线的位置（x值）

    // 先画y轴线，注意，缺省下是画在x=0的地方，但是如果 xmin > 0 或 xmax <0 则画在 x = xmin的地方
    var cp = []; // 保存canvas下的坐标, x=cp[0], y=cp[1]
    var ctx = ldc_plot.ctx

    ctx.save()
    ctx.beginPath()
    ctx.lineWidth = 5
    ctx.strokeStyle = 'black'
    cp = ldc_plot._project(orgx, rangey[0]); // 坐标转换为canvas坐标
    ctx.moveTo(cp[0], cp[1])
    cp = ldc_plot._project(orgx, rangey[1]); // 坐标转换为canvas坐标
    ctx.lineTo(cp[0], cp[1])
    ctx.stroke()

    // 再画刻度, 注意
    var step = 0

    if (type === 'normal') {
        step = (rangey[1] - rangey[0]) / ticks
        for (var y = rangey[0]; y <= rangey[1]; y += step) {
            ctx.beginPath()
            ctx.lineWidth = 1
            ctx.strokeStyle = 'grey'

            cp = ldc_plot._project(rangex[1], y); // 坐标转换为canvas坐标
            ctx.moveTo(cp[0], cp[1])
            cp = ldc_plot._project(rangex[0], y); // 坐标转换为canvas坐标
            ctx.lineTo(cp[0], cp[1])
            ctx.stroke()

            var tick_label = math.format(y, {
                notation: 'auto',
                precision: 2
            })
            ctx.strokeStyle = 'black'
            ctx.strokeText(tick_label, cp[0] + 10, cp[1])
        }
    } else if (type === 'log') {
        step = Math.log(rangey[1] / rangey[0]) / ticks
        var y = math.log(rangey[0])
        for (var i = 0; i <= ticks; i++) {
            ctx.beginPath()
            ctx.lineWidth = 1
            ctx.strokeStyle = 'grey'

            var yy = Math.exp(y + i * step)
            cp = ldc_plot._project(rangex[1], yy)
            ctx.moveTo(cp[0], cp[1])
            cp = ldc_plot._project(rangex[0], yy)
            ctx.lineTo(cp[0], cp[1])
            ctx.stroke()

            var tick_label = math.format(yy, {
                notation: 'auto',
                precision: 2
            })
            ctx.strokeStyle = 'black'
            ctx.strokeText(tick_label, cp[0] + 10, cp[1])
        }
    }
}