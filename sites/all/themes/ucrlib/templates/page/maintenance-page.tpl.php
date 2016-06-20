<!DOCTYPE html>
<!--[if lt IE <?php print $minie; ?> ]>    <html class="lt-ie<?php print $minie; ?> no-js" <?php print $html_attributes; ?>> <![endif]-->
<!--[if gte IE <?php print $minie; ?>]><!--> <html class="no-js" <?php //print $html_attributes; ?> <?php //print $rdf_attributes; ?>> <!--<![endif]-->
  <head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <!--[if gte IE 9]>
      <style type="text/css">
        .footer__wrapper:after {
          filter: none;
        }
      </style>
    <![endif]-->
    <link href="sites/all/themes/ucrlib/css/style.min.css" rel="stylesheet" />
    <?php print $scripts; ?>
  </head>
  <body class="<?php print $classes; ?> no-sidebar" <?php //print $body_attributes;?>>
    <div id="skip-link">
      <a href="#main" class="element-invisible element-focusable" role="link"><?php print t('Skip to main content'); ?></a>
    </div>
    <div id="page" class="page">
      <div class="container">
        <div class="header__wrapper" style="padding:10px 0 10px;">
          <div class="l-general">
            <header class="header">
              <div class="header__logo" style="float:none;text-align:center;">
                <span id="logo">
                  <a rel="home" title="UCR Library" href="<?php print $front_page; ?>">
                    <img alt="UCR Library Logo" src="<?php print $logo; ?>" typeof="foaf:Image">
                  </a>
                </span>
              </div>
            </header>
          </div>
        </div>
        <div class="page-title__wrapper" style="padding:20px 0 10px;">
          <div class="l-general" style="float:none;text-align:center;">
            <h1 class="title--page"><?php print $title; ?></h1>
          </div>
        </div>
        <div class="main-content__wrapper" style="padding:10px 0 30px;">
          <div class="l-general">
            <div class="main-content__wrapper-inner" style="padding:0 50px;">
              <div class="main-content" style="float:none;text-align:center;">
                <?php print render($content); ?>
              </div>
            </div>
          </div>
        </div>
        <div class="footer__wrapper">
          <div class="l-general">
            <footer class="footer">
            </footer>
          </div>
        </div>
        <div class="mobile-sidebar"></div>
      </div>
    </div>
  </body>
</html>
