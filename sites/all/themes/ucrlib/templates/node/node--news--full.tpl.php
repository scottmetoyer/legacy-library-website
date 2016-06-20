<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <div class="news__content">

    <?php if (isset($content['field_image'])) : ?>
      <?php print render($content['field_image']); ?>
    <?php else : ?>
      <div class="news__image">
        <img src="/<?php print $default_images['news']; ?>" alt="" />
      </div>
    <?php endif; ?>

    <?php if (isset($date)) { ?>
      <div class="news__date"><?php print $date; ?></div>
    <?php } ?>

    <?php print render($content['body']); ?>

    <?php if (isset($links_list)) : ?>
      <div class="news__related related">
        <h3 class="related__title"><?php print t('Related Information'); ?></h3>
        <div class="related__content">
          <?php print $links_list; ?>
        </div>
      </div>
    <?php endif; ?>

  </div>


  <aside class="news__sidebar-second">
      <div class="news__sidebar-section">
        <h3 class="news__sidebar-section-title"><?php print t('Sign up for UCR Library News'); ?></h3>
        <div class="news__sidebar-section-content"><p><a href="http://ucr.us10.list-manage.com/subscribe?u=3d3292965cebf17f0755f5ae2&id=7c4e1e6d46">Click here to sign up today!</a></p></div>
      </div>


    <?php if (isset($share)) { ?>
      <div class="news__sidebar-section">
        <h3 class="news__sidebar-section-title"><?php print t('Share'); ?></h3>
        <div class="news__sidebar-section-content"><?php print $share; ?></div>
      </div>
    <?php } ?>

    <?php if (isset($person_name)) { ?>
      <div class="news__sidebar-section">
        <h3 class="news__sidebar-section-title"><?php print t('Contact'); ?></h3>
        <div class="news__sidebar-section-content">
          <div class="news__contact-name"><?php print $person_name; ?></div>
          <div class="news__contact-job-title"><?php print $person_job_title; ?></div>
          <div class="news__contact-phone"><?php print $person_phone; ?></div>
          <div class="news__contact-email"><?php print $person_email; ?></div>
        </div>
      </div>
    <?php } ?>

  </aside>


</article>
