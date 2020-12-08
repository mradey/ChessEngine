var spawn = require('child_process').spawn;
var ahk = spawn('myProgram.exe');
const http = require('http');
var formidable = require('formidable');
const { stdin } = require('process');
const hostname = '127.0.0.1';
const port = 3000;
var output = "";
http.createServer(function (req, res) {
    if (req.url == '/makemove') {
      var form = new formidable.IncomingForm();
      form.parse(req, function (err, fields, files) {
        console.log(fields.move);
        ahk.stdin.write(fields.move + "\n");
        res.end();
      });
    } 
      res.writeHead(200, {'Content-Type': 'text/html'});
      res.write('<form action="makemove" method="post" enctype="multipart/form-data">');
      res.write('<input type="text" name="move"><br>');
      res.write('<input type="submit">');
      res.write('</form>');
      var bgnIdx = 0;
      var endIdx = 0;
      var lineSample = "------------------------\\n";
      for(let i = 0; i < 8; i++){
        aLine = output.substring(lineSample.length, lineSample.length * 2);
        output = output.substring(lineSample.length * 2);
        res.write("<p>" + aLine + "</p>");
      }
      return res.end();
    
  }).listen(8080);

ahk.stdout.on('data', function(data){
    output = data.toString();
    console.log(output)
});