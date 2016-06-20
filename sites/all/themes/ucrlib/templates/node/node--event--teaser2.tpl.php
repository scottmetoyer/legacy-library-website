<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="event__date">
    <?php if (isset($date_links['links'])) { ?>
      <?php if (count($date_links['links']) > 1) : ?>
        <?php print $date_links['links'][0]['date'] . ' - ' . $date_links['links'][count($date_links['links']) - 1]['date']; ?>
      <?php else : ?>
        <?php if(array_key_exists(0,$date_links['links']) )
        		print $date_links['links'][0]['date']; ?>
      <?php endif; ?>
    <?php } ?>
  </div>

  <div class="event__title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></div>

</article>
