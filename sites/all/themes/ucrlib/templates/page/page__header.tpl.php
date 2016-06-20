<div class="header__wrapper">
  <div class="l-general">
    <header class="header">


      <?php if ($logo) : ?>
        <div class="header__logo">
          <span id="logo">
            <a rel="home" title="<?php print $site_name; ?>" href="<?php print $front_page; ?>">
              <img alt="<?php print $site_name; ?> Logo" src="<?php print $logo; ?>" typeof="foaf:Image">
            </a>
          </span>
        </div>
      <?php endif; ?>

      <?php if ($page['header_content']) : ?>
        <div class="header__content">
          <?php print render($page['header_content']); ?>
        </div>
      <?php endif; ?>


    </header>
  </div>
</div>
