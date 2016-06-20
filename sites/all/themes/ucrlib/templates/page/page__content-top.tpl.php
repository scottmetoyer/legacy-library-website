<?php if (($messages && $show_messages) || $breadcrumb || isset($page['content_top']) || isset($page['help']) || $tabs || $action_links) : ?>
  <div class="content-top__wrapper">
    <div class="l-general">

      <?php print $breadcrumb; ?>

      <?php if ($show_messages) : ?>
        <?php print $messages; ?>
      <?php endif; ?>

      <?php if (isset($page['help'])) : ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>

      <?php print render($page['content_top']); ?>      

      <?php print render($tabs); ?>
      <?php print render($action_links); ?>

    </div>
  </div>
<?php endif; ?>
