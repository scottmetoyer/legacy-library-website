<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <div class="library__content">

    <?php print render($content['field_image']); ?>

    <?php if (isset($content['body'])) { ?>
      <h2><?php print t('About'); ?></h2>
      <?php print render($content['body']); ?>
    <?php } ?>

    <?php if (isset($content['field_google_map_address'])) : ?>
      <h2><?php print t('Map &amp; Directions'); ?></h2>
      <div class="library__map-directions">
        <iframe class="library__map" src="<?php print $map; ?>" frameborder="0" width="270" height="270"></iframe>

        <div class="library__directions-wrapper">
          <?php if (isset($google_directions)) { ?>
            <h3 class="library__directions-label"><?php print t('Get Directions'); ?></h3>
            <div><?php print $google_directions; ?></div>
          <?php } ?>

          <?php if (isset($public_transit)) { ?>
            <h3 class="library__directions-label"><?php print t('Public Transit'); ?></h3>
            <div><?php print $public_transit; ?></div>
          <?php } ?>

          <?php if (isset($parking)) { ?>
            <h3 class="library__directions-label"><?php print t('Parking'); ?></h3>
            <div><?php print $parking; ?></div>
          <?php } ?>

          <?php if (isset($ada_info)) { ?>
            <h3 class="library__directions-label"><?php print t('Visitors with Disabilities'); ?></h3>
            <div><?php print $ada_info; ?></div>
          <?php } ?>

        </div>
      </div>
    <?php endif; ?>

    <?php if (isset($address1) || isset($address2)) : ?>
      <div class="library__address">
        <h2><?php print t('Mailing Address'); ?></h2>

        <?php if (isset($address1)) { ?>
          <h3><?php print t('Mailing Address (US Postal Service, etc.)'); ?></h3>
          <p><?php print $address1; ?></p>
        <?php } ?>

        <?php if (isset($address2)) { ?>
          <h3><?php print t('Shipping Address (e.g. FedEx, Airborne, UPS)'); ?></h3>
          <p><?php print $address2; ?></p>
        <?php } ?>
      </div>
    <?php endif; ?>

    <?php if (isset($content['field_body2'])) { ?>
      <h2><?php print t('Building Features'); ?></h2>
      <?php print render($content['field_body2']); ?>
    <?php } ?>

  </div>


  <aside class="library__sidebar-second">

    <?php if (isset($hours)) { ?>
      <div class="library__hours">
        <h3 class="library__section-title"><?php print t('Today\'s Hours'); ?></h3>
        <?php print $hours; ?>
      </div>
    <?php } ?>

    <?php if (isset($phone)) { ?>
      <div class="library__phone">
        <h3 class="library__section-title"><?php print t('Phone'); ?></h3>
        <?php print $phone; ?>
      </div>
    <?php } ?>

    <?php if (isset($email)) {
    		if($email!=null){?>
      <div class="library__email">
        <h3 class="library__section-title"><?php print t('Email'); ?></h3>
        <?php print $email; ?>
      </div>
    <?php }} ?>

    <?php if (isset($subjects)) { ?>
      <div class="library__subjects">
        <h3 class="library__section-title"><?php print t('Subjects'); ?></h3>
        <?php print $subjects; ?>
      </div>
    <?php } ?>

  </aside>


</article>
