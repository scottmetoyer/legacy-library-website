This theme uses [Gulp](http://gulpjs.com/) for all build activities. This includes sass compilation, css minification, javascript linting/minification, etc.

Editing of sass & javascript files is done in their respective directories within this **src** directory.


# Installation


## 1. Install Node.js/npm & Gulp

Download and install node from the [Node.js website](http://nodejs.org/download/). Then install [Gulp](https://github.com/gulpjs/gulp/blob/master/docs/getting-started.md) in a terminal, by running (might need to use sudo):

    $ npm install -g gulp



## 2. Install Gulp Plugins

cd to this theme's src directory and run:

    $ npm install

This will install the required versions of each Gulp plugin.



# Usage


## 1. Run Gulp

    $ gulp

If you want to also reload your browser after css changes, run:

    $ gulp lr



## 2. Edit Sass & Javascript Files

Edit the sass and javascript files as usual, and upon save, Gulp will run the build task.
