<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="person__content">

    <h1 class="person__name"><?php print $title; ?></h1>

    <?php if (isset($job_title)) { ?>
      <h2 class="person__job-title"><?php print $job_title; ?></h2>
    <?php } ?>
      <?php if (isset($departments)) { ?>
        <span class="person__departments">Department: <?php print $departments; ?></span>
      <?php } ?>

    <div class="person__contact-info">
      <?php if (isset($email)) { ?>
        <span class="person__email"><?php print $email; ?></span>
      <?php } ?>
      <?php if (isset($phone)) { ?>
        <span class="person__phone"><?php print $phone; ?></span>
      <?php } ?>
      <?php if (isset($link)) { ?>
        <span class="person__suggest-purchase"><a href="<?php print $link; ?>"><?php print t('Suggest a Purchase'); ?></a></span>
      <?php } ?>

    </div>

    <?php print render($content['body']); ?>

    <?php if (isset($subject_specialties)) { ?>
      <div class="person__subjects">
        <h3 class="person__section-label"><?php print t('Subject Specialties'); ?></h3>
        <?php print $subject_specialties; ?>
      </div>
    <?php } ?>

  </div>


  <aside class="person__sidebar-first">

    <?php if (isset($content['field_image'])) : ?>
      <?php print render($content['field_image']); ?>
    <?php else : ?>
      <div class="person__image">
        <img src="/<?php print $default_images['person']; ?>" alt="" />
      </div>
    <?php endif; ?>

  </aside>


</article>
