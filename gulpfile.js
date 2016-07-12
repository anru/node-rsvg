"use strict";

var gulp = require('gulp');
var jshint = require('gulp-jshint');
var mocha = require('gulp-mocha');

gulp.task('jshint', function() {
    return gulp.src([
        'gulpfile.js',
        'index.js',
        'test/**/*.js'
    ])
        .pipe(jshint())
        .pipe(jshint.reporter('jshint-stylish'));
});

gulp.task('test', function() {
    var opts = {
        globals: ['should'],
        timeout: 3000,
        ui: 'bdd',
        reporter: 'spec',
        require: ['./test/helpers/chai.js']
    };

    return gulp.src([
        'test/helpers/chai.js',
        'test/**/*.test.js'
    ]).pipe(mocha(opts));
});


gulp.task('default', ['jshint']);
