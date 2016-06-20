<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <div class="subject-guide__content">

    <?php if (isset($carousel)) { ?>
      <div class="subject-guide__carousel">
        <?php htmlspecialchars_decode(print $carousel); ?>
      </div>
    <?php } ?>

    <?php print htmlspecialchars_decode(render($content['body'])); ?>
    <?php print htmlspecialchars_decode(render($content['field_faqs'])); ?>

  </div>


  <aside class="subject-guide__sidebar-second">

    <?php if (isset($subject_specialists)) { ?>
      <div class="subject-guide__subject-specialists">
        <h3 class="subject-guide__section-title"><?php print t('Subject Specialists'); ?></h3>
        <?php print htmlspecialchars_decode($subject_specialists); ?>
      </div>
    <?php } ?>

    <?php if (isset($course_guides)) { ?>
      <div class="subject-guide__course-guides">
        <h3 class="subject-guide__section-title"><?php print t('Course Guides'); ?></h3>
        <?php print htmlspecialchars_decode($course_guides); ?>
      </div>
    <?php } ?>

    <?php if (isset($databases)) { ?>
      <div class="subject-guide__databases">
        <h3 class="subject-guide__section-title"><?php print t('Databases'); ?></h3>
        <div class="read-more">
          <?php if(isset($all_databases))
          			print htmlspecialchars_decode($all_databases); ?>
        </div>
        <?php print htmlspecialchars_decode($databases); ?>
      </div>
    <?php } ?>

    <?php if (isset($topic_guides)) { ?>
      <div class="subject-guide__topic-guides">
        <h3 class="subject-guide__section-title"><?php print t('Topic Guides'); ?></h3>
        <?php print htmlspecialchars_decode($topic_guides); ?>
      </div>
    <?php } ?>

    <?php if (isset($research_tool_guides)) { ?>
      <div class="subject-guide__research-tool-guides">
        <h3 class="subject-guide__section-title"><?php print t('Tools &amp; Tutorials'); ?></h3>
        <?php print htmlspecialchars_decode($research_tool_guides); ?>
      </div>
    <?php } ?>

  </aside>


  <?php if (isset($links_list)) : ?>

    <footer class="subject-guide__related related">
      <h3 class="related__title"><?php print t('Related Information'); ?></h3>
      <div class="related__content">
        <?php print htmlspecialchars_decode($links_list); ?>
      </div>
    </footer>

  <?php endif; ?>


</article>
