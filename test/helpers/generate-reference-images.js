#!/usr/bin/env node
'use strict';
var Rsvg = require('../../index').Rsvg;
var fs = require('fs');

function renderSvg(svg) {
    return new Buffer(svg.render({
        format: 'png',
        width: svg.width,
        height: svg.height
    }).data);

}

function render(name) {
    var content = fs.readFileSync('./test/svg/'+name+'.svg');
    var svg = new Rsvg(content);
    fs.writeFile('./test/png/'+name+'.png' , renderSvg(svg), function(err) {
        if(err) {
            return console.log(err);
        }
        console.log('Wrote reference image for "' + name + '".');
    });
}

fs.readdir('./test/svg/', function(err, items) {
    for (var i=0; i<items.length; i++) {
        if(items[i].slice(-4)==='.svg'){
            var fn = items[i].slice(0,-4);
            render(fn);
        }
    }
});