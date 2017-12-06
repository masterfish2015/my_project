var vtape = {
    "起动类型": ["空-轻载起动", "重载起动"],

    "每天工作小时": ["<16", "10~16", ">16"],

    "工况": [{
        "类型": "载荷变动最小",
        "适应范围": "液体搅拌机、通风机和鼓风机（<=7.5kW）、离心机水泵和压缩机、轻载运输机",
    }, {
        "类型": "载荷变动小",
        "适应范围": "带式运输机（不均匀负荷）、通风机（>7.5kW）、旋转式水泵和压缩机（非离心式）、发电机、金属切削机床、印刷机、旋转筛、锯木机和木工机械",
    }, {
        "类型": "载荷变动较大",
        "适应范围": "制砖机、斗式提升机、往复式水泵和压缩机、起重机、磨粉机、冲剪机床、橡胶机械、振动筛、纺织机械、重载输送机",
    }, {
        "类型": "载荷变动很大",
        "适应范围": "破碎机（旋转式、颚式等）、磨碎机（球磨、棒磨、管磨）",
    }],

    "工况系数ka": [
        [
            [1.0, 1.1, 1.2],
            [1.1, 1.2, 1.3],
            [1.2, 1.3, 1.4],
            [1.3, 1.4, 1.5]
        ],
        [
            [1.1, 1.2, 1.3],
            [1.2, 1.3, 1.4],
            [1.4, 1.5, 1.6],
            [1.5, 1.6, 1.8]
        ]
    ],

    "普通V带和基准宽度窄V带基准直径": [
        //基准直径
        [20, 22.4, 25, 28, 31.5, 35.5, 40, 45, 50, 56, 63, 71, 75, 80, 85, 90, 95, 100, 106, 112, 118, 125, 132, 140, 150, 160, 170, 180, 200, 212, 224, 236, 250, 265, 280, 300, 315, 335, 355, 375, 400, 425, 450, 475, 500, 530, 560, 600, 630, 670, 710, 750, 800, 900, 1000, 1060, 1120, 1250, 1400, 1500, 1600, 1800, 1900, 2000, 2240, 2500],
        //+:表示只用于普通V带，*：表示二者都适合
        {
            "类型": ["Y"],
            "可用直径": [
                //基准直径，适用类型，圆跳动公差t
                [20, "+", 0.2],
                [22.4, "+", 0.2],
                [25, "+", 0.2],
                [28, "+", 0.2],
                [31.5, "+", 0.2],
                [35.5, "+", 0.2],
                [40, "+", 0.2],
                [45, "+", 0.2],
                [50, "+", 0.2],
                [56, "+", 0.2],
                [80, "+", 0.2],
                [90, "+", 0.2],
                [100, "+", 0.2],
                [112, "+", 0.3],
                [125, "+", 0.3],
            ]
        },
        {
            "类型": ["Z", "SPZ"],
            "可用直径": [
                [50, "+", 0.2],
                [56, "+", 0.2],
                [63, "*", 0.2],
                [71, "*", 0.2],
                [75, "*", 0.2],
                [80, "*", 0.2],
                [90, "*", 0.2],
                [100, "*", 0.2],
                [112, "*", 0.3],
                [125, "*", 0.3],
                [132, "*", 0.3],
                [140, "*", 0.3],
                [150, "*", 0.3],
                [160, "*", 0.3],
                [180, "*", 0.4],
                [200, "*", 0.4],
                [224, "*", 0.4],
                [250, "*", 0.4],
                [280, "*", 0.5],
                [315, "*", 0.5],
                [355, "*", 0.5],
                [400, "*", 0.5],
                [500, "*", 0.6],
                [630, "*", 0.6],
            ]
        },
        {
            "类型": ["A", "SPA"],
            "可用直径": [
                [75, "+", 0.2],
                [80, "+", 0.2],
                [85, "+", 0.2],
                [90, "*", 0.2],
                [95, "*", 0.2],
                [100, "*", 0.2],
                [106, "*", 0.3],
                [112, "*", 0.3],
                [118, "*", 0.3],
                [125, "*", 0.3],
                [132, "*", 0.3],
                [140, "*", 0.3],
                [150, "*", 0.3],
                [160, "*", 0.3],
                [180, "*", 0.4],
                [200, "*", 0.4],
                [224, "*", 0.4],
                [250, "*", 0.4],
                [280, "*", 0.5],
                [315, "*", 0.5],
                [355, "*", 0.5],
                [400, "*", 0.5],
                [450, "*", 0.6],
                [500, "*", 0.6],
                [560, "*", 0.6],
                [630, "*", 0.6],
                [710, "*", 0.8],
                [800, "*", 0.8],
            ]
        },
        {
            "类型": ["B", "SPB"],
            "可用直径": [
                [140, "*", 0.3],
                [150, "*", 0.3],
                [160, "*", 0.3],
                [170, "*", 0.4],
                [180, "*", 0.4],
                [200, "*", 0.4],
                [224, "*", 0.4],
                [250, "*", 0.4],
                [280, "*", 0.5],
                [315, "*", 0.5],
                [355, "*", 0.5],
                [400, "*", 0.5],
                [450, "*", 0.6],
                [500, "*", 0.6],
                [560, "*", 0.6],
                [600, "*", 0.6],
                [630, "*", 0.6],
                [710, "*", 0.8],
                [750, "*", 0.8],
                [800, "*", 0.8],
                [900, "*", 0.8],
                [1000, "*", 0.8],
                [1120, "*", 1.0],
            ]
        },
        {
            "类型": ["C", "SPC"],
            "可用直径": [
                [200, "+", 0.4],
                [212, "+", 0.4],
                [224, "*", 0.4],
                [236, "*", 0.4],
                [250, "*", 0.4],
                [265, "*", 0.5],
                [280, "*", 0.5],
                [300, "*", 0.5],
                [315, "*", 0.5],
                [335, "*", 0.5],
                [355, "*", 0.5],
                [400, "*", 0.5],
                [450, "*", 0.6],
                [500, "*", 0.6],
                [560, "*", 0.6],
                [600, "*", 0.6],
                [630, "*", 0.6],
                [710, "*", 0.8],
                [750, "*", 0.8],
                [800, "*", 0.8],
                [900, "*", 0.8],
                [1000, "*", 0.8],
                [1120, "*", 1.0],
                [1250, "*", 1.0],
                [1400, "*", 1.0],
                [1600, "*", 1.0],
                [2000, "*", 1.2]
            ]
        },
        {
            "类型": ["D"],
            "可用直径": [
                [355, "+", 0.5],
                [375, "+", 0.5],
                [400, "+", 0.5],
                [425, "+", 0.6],
                [450, "+", 0.6],
                [475, "+", 0.6],
                [500, "+", 0.6],
                [560, "+", 0.6],
                [600, "+", 0.6],
                [630, "+", 0.6],
                [710, "+", 0.8],
                [750, "+", 0.8],
                [800, "+", 0.8],
                [900, "+", 0.8],
                [1000, "+", 0.8],
                [1060, "+", 1.0],
                [1120, "+", 1.0],
                [1250, "+", 1.0],
                [1400, "+", 1.0],
                [1500, "+", 1.0],
                [1600, "+", 1.0],
                [1800, "+", 1.2],
                [2000, "+", 1.2]
            ]
        },
        {
            "类型": ["E"],
            "可用直径": [
                [500, "+", 0.6],
                [530, "+", 0.6],
                [560, "+", 0.6],
                [600, "+", 0.6],
                [630, "+", 0.6],
                [670, "+", 0.8],
                [710, "+", 0.8],
                [800, "+", 0.8],
                [900, "+", 0.8],
                [1000, "+", 0.8],
                [1120, "+", 1.0],
                [1250, "+", 1.0],
                [1400, "+", 1.0],
                [1500, "+", 1.0],
                [1600, "+", 1.0],
                [1800, "+", 1.2],
                [1900, "+", 1.2],
                [2000, "+", 1.2],
                [2240, "+", 1.2],
                [2500, "+", 1.2]
            ]
        }
    ],
    "普通V带基准长度": [
        { "基本长度": 200, "极限偏差": [-4, 8], "允许带型": ["Y"], "配组公差": 2 },
        { "基本长度": 240, "极限偏差": [-4, 8], "允许带型": ["Y"], "配组公差": 2 },
        { "基本长度": 250, "极限偏差": [-4, 8], "允许带型": ["Y"], "配组公差": 2 },
        { "基本长度": 280, "极限偏差": [-4, 9], "允许带型": ["Y"], "配组公差": 2 },
        { "基本长度": 316, "极限偏差": [-4, 9], "允许带型": ["Y"], "配组公差": 2 },
        { "基本长度": 355, "极限偏差": [-5, 10], "允许带型": ["Y"], "配组公差": 2 },
        { "基本长度": 400, "极限偏差": [-5, 10], "允许带型": ["Y", "Z"], "配组公差": 2 },
        { "基本长度": 450, "极限偏差": [-6, 11], "允许带型": ["Y", "Z"], "配组公差": 2 },
        { "基本长度": 500, "极限偏差": [-6, 11], "允许带型": ["Y", "Z"], "配组公差": 2 },
        { "基本长度": 560, "极限偏差": [-6, 13], "允许带型": ["Z"], "配组公差": 2 },
        { "基本长度": 630, "极限偏差": [-6, 13], "允许带型": ["Z", "A"], "配组公差": 2 },
        { "基本长度": 710, "极限偏差": [-7, 15], "允许带型": ["Z", "A"], "配组公差": 2 },
        { "基本长度": 800, "极限偏差": [-7, 15], "允许带型": ["Z", "A"], "配组公差": 2 },
        { "基本长度": 900, "极限偏差": [-8, 17], "允许带型": ["Z", "A", "B"], "配组公差": 2 },
        { "基本长度": 1000, "极限偏差": [-8, 17], "允许带型": ["Z", "A", "B"], "配组公差": 2 },
        { "基本长度": 1120, "极限偏差": [-10, 19], "允许带型": ["Z", "A", "B"], "配组公差": 2 },
        { "基本长度": 1250, "极限偏差": [-10, 19], "允许带型": ["Z", "A", "B"], "配组公差": 2 },
        { "基本长度": 1400, "极限偏差": [-11, 23], "允许带型": ["Z", "A", "B"], "配组公差": 4 },
        { "基本长度": 1600, "极限偏差": [-11, 23], "允许带型": ["Z", "A", "B"], "配组公差": 4 },
        { "基本长度": 1800, "极限偏差": [-13, 27], "允许带型": ["A", "B", "C"], "配组公差": 4 },
        { "基本长度": 2500, "极限偏差": [-13, 27], "允许带型": ["A", "B", "C"], "配组公差": 4 },
        { "基本长度": 2240, "极限偏差": [-16, 31], "允许带型": ["A", "B", "C"], "配组公差": 8 },
        { "基本长度": 2500, "极限偏差": [-16, 31], "允许带型": ["A", "B", "C"], "配组公差": 8 },
        { "基本长度": 2800, "极限偏差": [-18, 37], "允许带型": ["B", "C", "D"], "配组公差": 8 },
        { "基本长度": 3150, "极限偏差": [-18, 37], "允许带型": ["B", "C", "D"], "配组公差": 8 },
        { "基本长度": 3550, "极限偏差": [-22, 44], "允许带型": ["B", "C", "D"], "配组公差": 12 },
        { "基本长度": 4000, "极限偏差": [-22, 44], "允许带型": ["B", "C", "D"], "配组公差": 12 },
        { "基本长度": 4500, "极限偏差": [-28, 52], "允许带型": ["B", "C", "D", "E"], "配组公差": 12 },
        { "基本长度": 5000, "极限偏差": [-28, 52], "允许带型": ["B", "C", "D", "E"], "配组公差": 12 },
        { "基本长度": 5600, "极限偏差": [-32, 63], "允许带型": ["C", "D", "E"], "配组公差": 20 },
        { "基本长度": 6300, "极限偏差": [-32, 63], "允许带型": ["C", "D", "E"], "配组公差": 20 },
        { "基本长度": 7100, "极限偏差": [-38, 77], "允许带型": ["C", "D", "E"], "配组公差": 20 },
        { "基本长度": 8000, "极限偏差": [-38, 77], "允许带型": ["C", "D", "E"], "配组公差": 20 },
        { "基本长度": 9000, "极限偏差": [-46, 93], "允许带型": ["C", "D", "E"], "配组公差": 32 },
        { "基本长度": 10000, "极限偏差": [-46, 93], "允许带型": ["D", "E"], "配组公差": 32 },
        { "基本长度": 11200, "极限偏差": [-56, 112], "允许带型": ["D", "E"], "配组公差": 32 },
        { "基本长度": 12500, "极限偏差": [-56, 112], "允许带型": ["D", "E"], "配组公差": 32 },
        { "基本长度": 14000, "极限偏差": [-70, 140], "允许带型": ["D", "E"], "配组公差": 48 },
        { "基本长度": 16000, "极限偏差": [-70, 140], "允许带型": ["E"], "配组公差": 48 },
        { "基本长度": 18000, "极限偏差": [-85, 170], "允许带型": ["E"], "配组公差": 48 },
        { "基本长度": 20000, "极限偏差": [-85, 170], "允许带型": ["E"], "配组公差": 48 }
    ]
};


vtape.create_工况系数表 = function (target_id) {
    var str = "<table border='1' class='table'>";
    str += `<caption>${target_id}:工况系数K<sub>A</sub></caption>`;

    str += "<tr><td rowspan='4' colspan='2'>工况</td>";
    str += "<td colspan='6'>K<sub>A</sub></td></tr>";

    str += "<tr>"
    vtape["起动类型"].forEach(function (value) {
        str += `<td colspan='3'>${value}</td>`;
    });
    str += "</tr>";

    str += "<tr><td colspan='6'>每天工作小时数</td></tr>";

    str += "<tr>";
    for (let i = 0; i < 2; i++) {
        vtape["每天工作小时"].forEach(function (value) {
            str += `<td>${value}</td>`;
        });
    }
    str += "</tr>";

    vtape["工况"].forEach(function (v, i) {
        if (i % 2 === 0)
            str += "<tr>";
        else
            str += "<tr class='info'>";

        str += `<td>${v["类型"]}</td>`;
        str += `<td>${v["适应范围"]}</td>`;
        for (let k = 0; k < 2; k++) {
            for (let j = 0; j < vtape["每天工作小时"].length; j++) {
                str += `<td>${vtape["工况系数ka"][k][i][j]}</td>`;
            }
        }
        str += "</tr>";
    });

    str += "</table>";

    var obj = document.getElementById(target_id);
    obj.innerHTML = str;
};

vtape.create_普通V带和基准宽度窄V带基准直径表 = function (target_id) {
    var str = "<table border='1' class='table'>";
    str += `<caption>${target_id}: 普通V带和基准宽度窄V带基准直径表<br>+:表示只用于普通V带，&oplus;：表示二者都适合</caption>`;

    str += "<tr><td rowspan='2'>基准直径<br>(mm)</td><td colspan='8'>槽型</td></tr>";

    str += "<tr>";
    for (let i = 1; i < vtape["普通V带和基准宽度窄V带基准直径"].length; i++) {
        let type = vtape["普通V带和基准宽度窄V带基准直径"][i]["类型"];
        let name = "";
        type.forEach(function (v, j) {
            if (j > 0) name += "<br>";
            name += v;
        });
        str += `<td>${name}</td>`;
    }
    str += "<td>圆跳动公差t</td></tr>";

    vtape["普通V带和基准宽度窄V带基准直径"][0].forEach(function (v, i) {
        if (i % 2 === 0)
            str += `<tr><td>${v}</td>`;
        else
            str += `<tr class="info"><td>${v}</td>`;

        let t = 0;
        for (let j = 1; j < 8; j++) {
            let datas = vtape["普通V带和基准宽度窄V带基准直径"][j]["可用直径"];
            let flag = false;

            for (let k = 0; k < datas.length; k++) {
                if (datas[k][0] === v) {
                    let show = (datas[k][1] === "+") ?
                        datas[k][1] : "&oplus;";
                    str += `<td>${show}</td>`;
                    t = datas[k][2];
                    flag = true;
                    break;
                }
            }
            if (flag === false) str += `<td></td>`;
        }
        str += `<td>${t}</td>`;
        str += "</tr>";
    });

    str += "</table>";
    document.getElementById(target_id).innerHTML = str;
}

vtape.create_普通V带基准长度系列表 = function (target_id) {
    var str = `<table border='1' class='table'>`;
    str += `<caption>${target_id}: 普通V带基准长度系列表</caption>
          <tr><td colspan='2'>基准长度L<sub>d</sub></td>
              <td colspan='7'>带型</td>
              <td rowspan='2'>配组公差</td>
          </tr>
          <tr>
              <td>基本尺寸</td>
              <td>极限偏差</td>
              <td>Y</td>
              <td>Z</td>
              <td>A</td>
              <td>B</td>
              <td>C</td>
              <td>D</td>
              <td>E</td>
          </tr>`;

    vtape["普通V带基准长度"].forEach(function (v, i) {
        if (i % 2 === 0)
            str += `<tr>`;
        else
            str += `<tr class="info">`;

        str += `<td>${v["基本长度"]}</td><td>[${v["极限偏差"]}]</td>`;

        let type = ["Y", "Z", "A", "B", "C", "D", "E"];
        for (let j = 0; j < type.length; j++) {
            let flag = false;
            for (let k = 0; k < v["允许带型"].length; k++) {
                if (v["允许带型"][k] === type[j]) {
                    str += `<td>&radic;</td>`;
                    flag = true;
                    break;
                }
            }
            if (flag === false) {
                str += `<td></td>`;
            }
        }
        str += `<td>${v["配组公差"]}</td></tr>`;
    });
    str += "</table>";
    document.getElementById(target_id).innerHTML = str;

}