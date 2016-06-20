<?php
// Featured teaser on /news
?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <?php if (isset($content['field_image'])) : ?>
    <?php print render($content['field_image']); ?>
  <?php else : ?>
    <div class="news__image">
      <a href="<?php print $node_url; ?>">
        <img src="/<?php print $default_images['news']; ?>" alt="" />
      </a>
    </div>
  <?php endif; ?>

  <div class="news__column-second">
    <?php print render($content['field_date']); ?>

    <h3 class="news__title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>

    <?php print render($content['body']); ?>

    <div class="news__read-more">
      <?php print $read_more; ?>
    </div>
  </div>


</article>
