<?php
/**
 * @file
 * Template for rendering opening hours week.
 */
?>
<div class="ucrlib-opening-hours-open" data-nid="<?php print $nid; ?>" data-date="<?php print $date; ?>">
  <div class="title"><?php print $title; ?></div>
  <div class="status status--<?php print $status; ?>"><?php print $status; ?></div>
  <?php if (!empty($day)) { ?>
    <div class="hours"><?php print $day; ?></div>
  <?php } ?>
</div>
