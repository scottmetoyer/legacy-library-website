<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (isset($content['field_google_map_address'])) : ?>
    <div class="library__map-directions">
      <iframe class="library__map" src="<?php print $map; ?>" frameborder="0" width="270" height="270"></iframe>

      <div class="library__directions-wrapper">
        <h2 class="library__directions-title"><?php print $title ?></h2 class="library__directions-title">

        <?php if (isset($google_directions)) { ?>
          <div class="library__directions-google">
            <h3 class="library__directions-label"><?php print t('Get Directions'); ?></h3>
            <div><?php print $google_directions; ?></div>
          </div>
        <?php } ?>

        <?php if (isset($parking)) { ?>
          <div class="library__directions-parking">
            <h3 class="library__directions-label"><?php print t('Parking'); ?></h3>
            <div><?php print $parking; ?></div>
          </div>
        <?php } ?>

        <?php if (isset($public_transit)) { ?>
          <div class="library__directions-public-transit">
            <h3 class="library__directions-label"><?php print t('Public Transit'); ?></h3>
            <div><?php print $public_transit; ?></div>
          </div>
        <?php } ?>

        <?php if (isset($ada_info)) { ?>
          <div class="library__directions-ada">
            <h3 class="library__directions-label"><?php print t('Visitors with Disabilities'); ?></h3>
            <div><?php print $ada_info; ?></div>
          </div>
        <?php } ?>

      </div>
    </div>
  <?php endif; ?>

</article>
