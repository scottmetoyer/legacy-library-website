/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

CKEDITOR.editorConfig = function(config) {
  // Block width/height inline styles
  config.disallowedContent = 'img{width,height}';
  config.extraAllowedContent = 'img[width,height]; abbr[title]; h1; span{*}(*)[*];';

  // allow i tags to be empty (for FontAwesome)
  CKEDITOR.dtd.$removeEmpty['span'] = false;

  // config.allowedContent = true;
};
