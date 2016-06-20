'use strict';

// Include Gulp
var gulp = require('gulp'),

// Include Plug-ins
changed = require('gulp-changed'),
concat = require('gulp-concat'),
globbing = require('gulp-css-globbing'),
imagemin = require('gulp-imagemin'),
jshint = require('gulp-jshint'),
livereload = require('gulp-livereload'),
minifyCSS = require('gulp-minify-css'),
prefix = require('gulp-autoprefixer'),
rename = require('gulp-rename'),
sass = require('gulp-sass'),
sourcemaps = require('gulp-sourcemaps'),
stripDebug = require('gulp-strip-debug'),
stylish = require('jshint-stylish'),
uglify = require('gulp-uglify'),
util = require('gulp-util'),
watch = require('gulp-watch');


////////////////////////////////////////////////////////////////////////////////
// Javascript
////////////////////////////////////////////////////////////////////////////////

// JS hint
gulp.task('lint', function() {
  return gulp.src([
      'js/theme/**.*.js'
    ])
    .pipe(jshint())
    .pipe(jshint.reporter(stylish));
});

// Vendor scripts
gulp.task('vendor-scripts', function() {
  return gulp.src([
      'js/vendor/**/*.js'
    ])
    .pipe(concat('vendor.js'))
    .pipe(gulp.dest('../js'));
});

// Theme scripts
gulp.task('theme-scripts', ['lint'], function() {
  return gulp.src([
      'js/theme/**/*.js'
    ])
    .pipe(concat('theme.js'))
    .pipe(gulp.dest('../js'));
});

// Production-ify scripts
gulp.task('scripts', ['vendor-scripts', 'theme-scripts'], function() {
  return gulp.src([
      '../js/vendor.js',
      '../js/theme.js'
    ])
    .pipe(concat('all.min.js'))
    .pipe(stripDebug())
    .pipe(uglify())
    .pipe(gulp.dest('../js'));
});

////////////////////////////////////////////////////////////////////////////////
// Sass
////////////////////////////////////////////////////////////////////////////////

// Sass files
gulp.task('sass', function() {
  var s = sass();
  s.on('error', function(e) {
    util.beep();
    util.log(e);
    s.emit('end');
  });

  return gulp.src([
      'sass/*.scss'
    ])
    .on('error', function(err) {
      console.log(err.message);
    })
    .pipe(globbing({
      extensions: ['.scss']
    }))
    .pipe(sourcemaps.init())
    .pipe(globbing())
    .pipe(s)
    .pipe(sourcemaps.write())
    .pipe(prefix('last 2 versions', '> 1%', 'ie 8'))
    .pipe(gulp.dest('../css'))
    .pipe(minifyCSS())
    .pipe(rename({ suffix: '.min' }))
    .pipe(gulp.dest('../css'));
});

////////////////////////////////////////////////////////////////////////////////
// Images
////////////////////////////////////////////////////////////////////////////////

// Minify images
gulp.task('imagemin', function() {
  return gulp.src([
      'images/**/*'
    ])
    .pipe(changed('../images'))
    .pipe(imagemin())
    .pipe(gulp.dest('../images'));
});

////////////////////////////////////////////////////////////////////////////////
// Default task
////////////////////////////////////////////////////////////////////////////////

gulp.task('default', ['scripts', 'sass', 'imagemin'], function() {
  gulp.watch('js/**/*', ['scripts']);
  gulp.watch('sass/**/*', ['sass']);
  gulp.watch('images/**/*', ['imagemin']);
});

////////////////////////////////////////////////////////////////////////////////
// Live reload task
////////////////////////////////////////////////////////////////////////////////

gulp.task('lr', ['default'], function() {
  livereload.listen();

  gulp.watch('../css/style.css').on('change', livereload.changed);
});
