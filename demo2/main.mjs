var express = require('express');

let app = express();

app.use(express.static("html"));

app.get('/', function(req, res) {
    res.sendFile("/index.html");
});

var server = app.listen(3000, 'localhost', function() {
    var host = server.address().address;
    var port = server.address().port;

    console.log('Example app listening at http://%s:%s', host, port);
});