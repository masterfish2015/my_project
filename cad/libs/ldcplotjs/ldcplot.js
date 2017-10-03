var ldc_plot = {};
ldc_plot.init = function(option) {
    ldc_plot.target =document.getElementById(option.target_id);
    if (this.target === undefined)
        return;

    //create canvas and set width && height
    ldc_plot.canvas = document.createElement("canvas");
    ldc_plot.canvas.width = option.width || 400;
    ldc_plot.canvas.height = option.height || 300;

    ldc_plot.target.appendChild(this.canvas);
    ldc_plot.target.width = ldc_plot.canvas.width;

    ldc_plot.ctx = this.canvas.getContext("2d");

    //draw function graph
    ldc_plot.data = option.data;
    if (ldc_plot.data === undefined)
        return;

    //range of axis
    ldc_plot.x_axis_range = [0, 10];
    if (option.x_axis && option.x_axis.range) {
        ldc_plot.x_axis_range = option.x_axis.range;
    }
    ldc_plot.y_axis_range = [0, 10];
    if (option.y_axis && option.y_axis.range) {
        ldc_plot.y_axis_range = option.y_axis.range;
    }
    //label of axis
    ldc_plot.x_label = "";
    if (option.x_axis && option.x_axis.label) {
        ldc_plot.x_label = option.x_axis.label;
    }
    ldc_plot.y_label = "";
    if (option.y_axis && option.y_axis.label) {
        ldc_plot.y_label = option.y_axis.label;
    }
    //ticks of each axis
    ldc_plot.x_axis_ticks = 10;
    if (option.x_axis && option.x_axis.ticks) {
        ldc_plot.x_axis_ticks = option.x_axis.ticks;
    }
    ldc_plot.y_axis_ticks = 10;
    if (option.y_axis && option.y_axis.ticks) {
        ldc_plot.y_axis_ticks = option.y_axis.ticks;
    }

    ldc_plot._draw_axis("x");
    ldc_plot._draw_axis("y");

    //draw dates
    this.data.forEach(function(value, index, array) {
        var type = value.type || "function";
        var fn = value.fn;
        var range = value.range || [0, 10];
        var samples = value.samples || 100;
        var step = (range[1] - range[0]) / samples;
        var color = value.color || "black";
        var width = value.width || 1;
        var is_first = true;
        var title = value.title || "fun-" + index;
        var ctx = ldc_plot.ctx;
        var canvas = ldc_plot.canvas;

        ctx.beginPath();
        ctx.strokeStyle = color;
        ctx.lineWidth = width;
        ctx.lineCap = "round";
        ctx.lineJoin = "round";

        if (type === "function") {
            for (var x = range[0]; x < range[1]; x += step) {
                var y = math.eval(fn, {
                    x: x
                });
                var cp = ldc_plot._project(x, y);
                if (is_first === true) {
                    ctx.moveTo(cp[0], cp[1]);
                    is_first = false;
                } else {
                    ctx.lineTo(cp[0], cp[1]);
                }
            }
        } else if (type === "points") {
            var points = value.points;
            for (var i = 0; i < points.length; i++) {
                var x = points[i][0],
                    y = points[i][1];
                cp = ldc_plot._project(x, y);
                ctx.moveTo(cp[0], cp[1]);
                ctx.arc(cp[0], cp[1], width, 0, 2 * Math.PI, true);
                ctx.fillText(points[i][2],cp[0]+10,cp[1]+10);
            }
        }

        ctx.stroke();
        var legend_width = ctx.measureText(title).width;
        ctx.fillStyle = color;
        ctx.fillRect(canvas.width - legend_width, index * 50, legend_width, 20);
        ctx.lineWidth = 1;
        ctx.strokeText(title, canvas.width - legend_width, index * 50 + 30);
    });
};

ldc_plot._project = function(x, y) {
    var cx, cy;
    var xmin = ldc_plot.x_axis_range[0],
        xmax = ldc_plot.x_axis_range[1],
        ymin = ldc_plot.y_axis_range[0],
        ymax = ldc_plot.y_axis_range[1],
        cw = ldc_plot.canvas.width,
        ch = ldc_plot.canvas.height;
    cx = (x - xmin) * cw / (xmax - xmin);
    cy = (ymax - y ) * ch / (ymax - ymin);
    return [cx, cy];
}

ldc_plot._draw_axis = function(x_or_y) {
    var range, label, ticks, orgx=0, orgy=0;
    switch(x_or_y){
      case "x":
        range = ldc_plot.x_axis_range;
        label = ldc_plot.x_label;
        ticks = ldc_plot.x_axis_ticks;
        break;
      case "y":
        range = ldc_plot.y_axis_range;
        label = ldc_plot.y_label;
        ticks = ldc_plot.y_axis_ticks;
        break;
    }
    if(ldc_plot.x_axis_range[0]>0 || ldc_plot.x_axis_range[1]<0){
      orgx = ldc_plot.x_axis_range[0];
    }
    if(ldc_plot.y_axis_range[0]>0 || ldc_plot.y_axis_range[1]<0){
      orgy = ldc_plot.y_axis_range[0];
    }
    var cp = [];
    //draw axis
    var ctx = ldc_plot.ctx;

    //draw ticks
    var step = (range[1] - range[0]) / ticks;
    ctx.save();

    for (var i = range[0]; i < range[1]; i += step) {
      var str = math.format(i, {
            notation: "auto",
            precision: 3
      });

      if(x_or_y === "x"){
        ctx.beginPath();
        ctx.setLineDash([5, 3]); /*dashes are 5px and spaces are 3px*/
        cp = ldc_plot._project(i, ldc_plot.y_axis_range[0]);
        ctx.moveTo(cp[0],cp[1]);
        cp = ldc_plot._project(i, ldc_plot.y_axis_range[1])
        ctx.lineTo(cp[0],cp[1]);
        ctx.stroke();

        ctx.beginPath();
        ctx.setLineDash([]);
        cp = ldc_plot._project(i, orgy);
        ctx.strokeText(str, cp[0] - ctx.measureText(str).width / 2, cp[1] - 8);
        ctx.stroke();
      }else{ //y
        ctx.beginPath();
        ctx.setLineDash([5, 3]); /*dashes are 5px and spaces are 3px*/
        cp = ldc_plot._project(ldc_plot.x_axis_range[0], i);
        ctx.moveTo(cp[0],cp[1]);
        cp = ldc_plot._project(ldc_plot.x_axis_range[1], i);
        ctx.lineTo(cp[0], cp[1]);
        ctx.stroke();

        ctx.beginPath();
        ctx.setLineDash([]);
        cp = ldc_plot._project(orgx, i);
        ctx.strokeText(str, cp[0] +8, cp[1] +10);
        ctx.stroke();
      }
    }

    ctx.beginPath();
    ctx.strokeStyle = "darkblue";
    ctx.lineWidth = 8;
    //draw axis
    if(x_or_y === "x"){
      cp = ldc_plot._project(orgx, orgy);
      ctx.moveTo(cp[0], cp[1]);
      cp = ldc_plot._project(range[1], orgy);
      ctx.lineTo(cp[0], cp[1]);
      ctx.stroke();
      //draw label
      ctx.lineWidth = 1;
      ctx.strokeText(label, cp[0] - ctx.measureText(label).width, cp[1] - 10);
    }else{ //y
      cp = ldc_plot._project(orgx, orgy);
      ctx.moveTo(cp[0], cp[1]);
      cp = ldc_plot._project(orgx, range[1]);
      ctx.lineTo(cp[0], cp[1]);
      ctx.stroke();
      //draw label
      ctx.lineWidth = 1;
      ctx.strokeText(label, cp[0]+10, cp[1] +20);
    }
    ctx.restore();
}
