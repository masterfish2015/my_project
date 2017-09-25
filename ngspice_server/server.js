const { exec } = require('child_process');
let express = require('express');
let fs = require("fs");
let math = require("mathjs");


let app = express();
var bodyParser = require('body-parser');

/*
exec('ls -l', (error, stdout, stderr) => {
  if (error) {
    console.error(`exec error: ${error}`);
    return;
  }
  console.log(`stdout: ${stdout}`);
  console.log(`stderr: ${stderr}`);
});
*/
app.use(express.static(__dirname + '/html'));
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.get("/", function(request, response) {
    response.sendFile('index.html');
});

app.post("/ngspice", function(request, response) {
    console.log(request.body);
    let dt = new Date();
    let realfilename = "H" + dt.getHours() + "-M" + dt.getMinutes() + "-S" + dt.getSeconds() + "-MS" + dt.getMilliseconds();
    console.log(realfilename);
    let filestring = "html/spice/" + realfilename;

    fs.writeFile(filestring + ".cir", request.body["spice-source"] || "", "utf8", function(error) {
        if (!error) {
            exec("ngspice -b -o " + filestring + ".log " + filestring + ".cir",
                function(error, stdout, stderr) {
                    //if (!error) {
                    fs.readFile(filestring + ".log", "utf8", function(err, data) {
                        if (!err) {
                            //取出数据
                            let lines = data.split('\n');
                            let return_data = {};
                            let flag = false;
                            let index = 0;
                            for (let line in lines) {
                                //console.log(lines[line]);
                                if (lines[line].indexOf("No. of Data Rows :") >= 0) {
                                    flag = true;
                                } else if (lines[line].indexOf("CPU time since last call:") >= 0) {
                                    flag = false;
                                }
                                if (flag === true) {
                                    return_data[index++] = lines[line];
                                }
                            }
                            response.json(return_data);
                        } else {
                            console.log(err);
                        }
                    });
                    //} else {
                    console.log(error);
                    console.log("stderr:" + stderr);
                    console.log("stdout:" + stderr);
                    //}
                });
        }
    });
});

app.listen(3000, function() {
    console.log("listen at : 127.0.0.1:3000");
});