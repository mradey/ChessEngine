var express = require('express');
var app = express();

app.set("view engine","vash")

var spawn = require('child_process').spawn;
var ahk = spawn('../engine.exe');
const http = require('http');
const { stdin } = require('process');
var vash = require('vash');
const fs = require('fs');

let rawdata = fs.readFileSync('../board.json');
let board = JSON.parse(rawdata);
console.log(board);

const hostname = '127.0.0.1';
const port = 3000;
pieceUnicodeMap = {
    "B" : {
      'K':'\u265A',
      'Q':'\u265B',
      'R':'\u265C',
      'B':'\u265D',
      'N':'\u265E',
      'P':'\u265F'
    },
    "W" : {
       'K':'\u2654',
       'Q':'\u2655',
       'R':'\u2656',
       'B':'\u2657',
       'N':'\u2658',
       'P':'\u2659',
    }
}



app.get('/', function (req, res) {
    
  res.render('index', {"board":board, "map":pieceUnicodeMap});

});

var server = app.listen(5000, function () {
  console.log('Server is running..');
});

ahk.stdout.on('data', function(data){
    output = data.toString();
    console.log(output)
});

app.post("/locations", function(request, response) {
  console.log(request.body);
  return response.json({}, 200);
});