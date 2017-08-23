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
    let realfilename = Math.round(Math.random() * 10000).toString();
    let filestring = "html/spice/" + Math.round(Math.random() * 10000);
    let filename = filestring + ".cir";
    console.log("filename:" + filename);

    fs.open(filename, "w+", function(err, fd) {
        if (!err) {
            console.log(fd);
            fs.write(fd, request.body["spice-source"], function(err, w, b) {
                fs.close(fd, function(err) {
                    console.log(filename + " close.");
                    //file create ok, do SPICE analysis.
                    exec("ngspice -b -o " + filestring + ".log " + filename,
                        function(error, stdout, stderr) {
                            if (!error) {
                                response.sendFile(filestring + ".log");
                            } else {
                                console.log(error);
                                console.log("stderr:" + stderr);
                                console.log("stdout:" + stderr);
                            }
                        });
                });
            });
        } else {
            console.log(err);
        }
    });

    //response.json(request.body);
});

app.listen(3000, function() {
    console.log("listen at : 127.0.0.1:3000");
});