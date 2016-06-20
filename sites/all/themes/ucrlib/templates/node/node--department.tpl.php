<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="department__content">

    <div class="department__contact-info">
      <?php if (isset($email)) { ?>
        <span class="department__email"><?php print $email; ?></span>
      <?php } ?>
      <?php if (isset($phone)) { ?>
        <span class="department__phone"><?php print $phone; ?></span>
      <?php } ?>
      <?php if (isset($fax)) { ?>
        <span class="department__fax"><?php print $fax; ?></span>
      <?php } ?>
    </div>

    <?php if (isset($description)) { ?>
      <div class="department__description">
        <?php print $description; ?>
      </div>
    <?php } ?>

    <?php if (isset($staff)) { ?>
      <div class="department__staff">
        <h2><?php print t('Staff'); ?></h2>
        <?php print $staff; ?>
      </div>
    <?php } ?>

    <?php if (isset($hours)) { ?>
      <div class="department__hours">
        <h2><?php print t('Department Hours'); ?></h2>
        <?php print $hours; ?>
      </div>
    <?php } ?>

    <?php if (isset($links_list)) { ?>
      <div class="department__links related">
        <h3><?php print t('You May Also Be Looking For'); ?></h3>
        <?php print $links_list; ?>
      </div>
    <?php } ?>


  </div>

</article>
