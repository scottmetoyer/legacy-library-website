<?php
/**
 * @file
 * Template for rendering an opening hour instance.
 */
?>
<div class="instance">
  <?php if ($appointment==1):?>
    <span class="time" title="<?php echo t('Opening time'); ?>"><?php print t('By appointment') ?></span>
  <?php elseif ($twentyfourhours==1):?>
    <span class="time" title="<?php echo t('Opening time'); ?>"><?php print t('open 24 hrs') ?></span>
  <?php else: ?>
    <span class="time start_time" title="<?php print t('Opening time'); ?>"><?php print $start_time ?></span> – <span class="time end_time" title="<?php print t('Closing time'); ?>"><?php print $end_time ?></span>
  <?php endif; ?>

  <?php if ($category): ?>
    <span class="category"><?php print $category ?></span>
  <?php endif; ?>
  <?php if ($notice): ?>
    <br><span class="notice"><?php print $notice ?></span>
  <?php endif; ?>
</div>
