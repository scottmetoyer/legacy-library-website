<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (isset($carousel)) { ?>
    <div class="exhibit__carousel">
      <?php print $carousel; ?>
    </div>
  <?php } ?>


  <div class="exhibit__content">

    <?php print render($content['field_paragraphs_body']); ?>

  </div>


  <?php if (isset($links_list)) : ?>

    <footer class="exhibit__related related">
      <h3 class="related__title"><?php print t('Related Information'); ?></h3>
      <div class="related__content">
        <?php print $links_list; ?>
      </div>
    </footer>

  <?php endif; ?>


</article>
