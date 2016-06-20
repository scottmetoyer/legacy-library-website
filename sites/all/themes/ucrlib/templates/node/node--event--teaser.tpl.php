<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (isset($content['field_image'])) : ?>
    <?php print render($content['field_image']); ?>
  <?php else : ?>
    <div class="image-item event__image event--teaser__image">
      <a href="<?php print $node_url; ?>">
        <img src="/<?php print $default_images['event']; ?>" alt="" />
      </a>
    </div>
  <?php endif; ?>

  <h3 class="event__title event--teaser__title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>

  <div class="event__attributes">

    <?php if (isset($date_links['links'])) { ?>
      <div class="event__attribute">
        <span class="event_attribute-label"><?php print t('Date'); ?>:</span>
        <?php if (count($date_links['links']) > 1) : ?>
          <span class="event__attribute-content">
            <?php print $date_links['links'][0]['date'] . ' - ' . $date_links['links'][count($date_links['links']) - 1]['date']; ?>
          </span>
        <?php else : ?>
          <span class="event__attribute-content">
            <?php print $date_links['links'][0]['date']; ?>
          </span>
        <?php endif; ?>
      </div>
    <?php } ?>

    <?php if (isset($hours)) { ?>
      <div class="event__attribute">
        <span class="event_attribute-label"><?php print t('Time'); ?>:</span>
        <span class="event__attribute-content"><?php print $hours; ?></span>
      </div>
    <?php } ?>

    <?php if (isset($location)) { ?>
      <div class="event__attribute">
        <span class="event_attribute-label"><?php print t('Location'); ?>:</span>
        <span class="event__attribute-content"><?php print $location; ?></span>
      </div>
    <?php } ?>

  </div>

  <?php if (isset($event_type)) { ?>
    <?php if (isset($color)) : ?>
      <div class="event__type" style="background-color:<?php print $color; ?>;color:#fff;">
        <?php print $event_type; ?>
      </div>
    <?php else : ?>
      <div class="event__type">
        <?php print $event_type; ?>
      </div>
    <?php endif; ?>
  <?php } ?>

</article>
