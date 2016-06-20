<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="collection__content">

    <header class="collection__header">

      <h1 class="collection__title"><?php print $title; ?></h1>

      <?php if (isset($libraries)) { ?>
        <h2 class="collection__library">
          <?php print t('Located in'); ?>: <?php print $libraries; ?>
        </h2>
      <?php } ?>

    </header>

    <div class="collection__content-inner">

      <?php if (isset($content['body']) && isset($content['field_body2'])) : ?>
        <div class="collection__body-tabs">

          <div class="collection__body-tabs-tabs">
            <div class="collection__body-tabs-tab">
              <a href="#" data-st-trigger="1"><?php print t('Collection Overview'); ?></a>
            </div>
            <div class="collection__body-tabs-tab">
              <a href="#" data-st-trigger="2"><?php print t('Subsidiary Collections'); ?></a>
            </div>
          </div>

          <div class="collection__body-tabs-panes">
            <div class="collection__body-tabs-pane" data-st-target="1">
              <?php print render($content['body']); ?>
            </div>
            <div class="collection__body-tabs-pane" data-st-target="2">
              <?php print render($content['field_body2']); ?>
            </div>
          </div>

        </div>
      <?php else : ?>
        <?php print render($content['body']); ?>
        <?php print render($content['field_body2']); ?>
      <?php endif; ?>

      <?php print render($content['field_faqs']); ?>

    </div>

    <aside class="collection__sidebar-second">

      <?php if (isset($cta_content)) { ?>
        <div class="collection__access-collection">
          <h3 class="collection__section-title"><?php print t('Access This Collection'); ?></h3>
          <?php print $cta_content; ?>
        </div>
      <?php } ?>

      <?php if (isset($person_name)) {
      	if($person_name!=null && $person_name!=""){?>
        <div class="collection__contact-person">
          <h3 class="collection__section-title"><?php print t('Contact'); ?></h3>
          <div class="collection__contact-person-photo">
            <?php print $person_photo; ?>
          </div>
          <div class="collection__contact-person-name">
            <?php print $person_name; ?>
          </div>
          <div class="collection__contact-person-job-title">
            <?php print $person_job_title; ?>
          </div>
        </div>
      <?php } }?>

      <?php if (isset($department)) {
      	if($department!="" && $department!=null){?>
        <div class="collection__contact-department">
          <h3 class="collection__section-title"><?php print t('Contact Department'); ?></h3>
          <div class="collection__contact-department">
            <?php print $department; ?>
          </div>
        </div>
      <?php }} ?>


    </aside>

  </div>


  <aside class="collection__sidebar-first">

    <?php print render($content['field_image']); ?>

    <?php if (isset($subjects)) { ?>
      <div class="collection__subject-areas">
        <h3 class="collection__section-title"><?php print t('Subject Areas'); ?></h3>
        <?php print $subjects; ?>
      </div>
    <?php } ?>

    <?php if (isset($links_list)) { ?>
      <div class="collection__related-resources">
        <h3 class="collection__section-title"><?php print t('Related Resources'); ?></h3>
        <?php print $links_list; ?>
      </div>
    <?php } ?>

    <?php if (isset($collections)) { ?>
      <div class="collection__related-collections">
        <h3 class="collection__section-title"><?php print t('Related Collections'); ?></h3>
        <?php print $collections; ?>
      </div>
    <?php } ?>

    <?php if (isset($guides)) { ?>
      <div class="collection__related-guides">
        <h3 class="collection__section-title"><?php print t('Related Guides'); ?></h3>
        <?php print $guides; ?>
      </div>
    <?php } ?>

  </aside>


</article>
