<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (isset($carousel) && $carousel_width == 'full') { ?>
    <div class="page__carousel page__carousel--full">
      <?php print $carousel; ?>
    </div>
  <?php } ?>


  <div class="page__content">

    <?php if (isset($carousel) && $carousel_width == 'two_thirds') { ?>
      <div class="page__carousel page__carousel--two-thirds">
        <?php print $carousel; ?>
      </div>
    <?php } ?>

    <?php print render($content['body']); ?>
    <?php print render($content['field_faqs']); ?>

  </div>


  <?php if (isset($cta_title) && isset($cta_content)) : ?>

    <aside class="page__cta cta">
      <h3 class="cta__title"><?php print $cta_title; ?></h3>
      <div class="cta__content"><?php print $cta_content; ?></div>
    </aside>

  <?php endif; ?>


  <?php if (isset($links_list)) : ?>

    <footer class="page__related related">
      <h3 class="related__title"><?php print t('Related Information'); ?></h3>
      <div class="related__content">
        <?php print $links_list; ?>
      </div>
    </footer>

  <?php endif; ?>


</article>
