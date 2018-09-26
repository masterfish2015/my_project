const path = require('path');

module.exports = {
    entry: "./src/app.jsx",
    output: {
        path: path.resolve(__dirname, "dist"),
        filename: "build.js"
    },
    devServer: {
        contentBase: '.'
    },
    module: {
        rules: [{
            test: /\.jsx$/,
            exclude: /node_modules/,
            loader: "babel-loader",
            options: {
                presets: ["env", "react"]
            }
        }]
    }
}