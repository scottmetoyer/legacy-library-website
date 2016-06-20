<!DOCTYPE html>
<!--[if lt IE 9]>    <html class="lt-ie9 no-js" <?php print $html_attributes; ?>> <![endif]-->
<!--[if gte IE 9]><!--> <html class="no-js" <?php print $html_attributes; ?> <?php print $rdf_attributes; ?>> <!--<![endif]-->
  <head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <style type="text/css" media="all">
      @import url(<?php print '/' . path_to_theme() . '/css/map.min.css' ?>);
    </style>
  </head>
  <body class="<?php print $classes; ?>" <?php print $body_attributes;?>>
    <?php print $page; ?>
  </body>
</html>
