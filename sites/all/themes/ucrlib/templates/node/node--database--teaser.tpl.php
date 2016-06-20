<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
   <?php if ((isset($type_of_access) && $type_of_access == TRUE)) : ?>
    <div class="database__bools">
      <?php if (isset($type_of_access) && $type_of_access == TRUE) { ?>
        <span class="database__require-logged-in" title="<?php print t('Users must be logged in'); ?>"></span>
      <?php } ?>
      <?php if (isset($is_trial) && $is_trial == TRUE) { ?>
        <span class="database__trial-database" title="<?php print t('This is a trial database. Expires on date listed below'); ?>"></span>
      <?php } ?>
    </div>
  <?php endif; ?>
   <?php if ($type_of_access == 0) : ?>
    <div class="database__bools">
        <span class="database__open_access" title="<?php print t('Free to access'); ?>"></span>
      <?php if (isset($is_trial) && $is_trial == TRUE) { ?>
        <span class="database__trial-database" title="<?php print t('This is a trial database. Expires on date listed below'); ?>"></span>
      <?php } ?>
    </div>
  <?php endif; ?>

  <div class="database__content">
    <h3 class="database__title"><a href="<?php print $link; ?>"><?php print $title; ?></a></h3>

    <div class="database__description"><?php print $description; ?></div>

    <?php if (isset($trial_end_date)) { ?>
      <div class="database__trial-end-date"><?php print t('Trial ends on'); ?> <?php print $trial_end_date; ?></div>
    <?php } ?>
  </div>

</article>
