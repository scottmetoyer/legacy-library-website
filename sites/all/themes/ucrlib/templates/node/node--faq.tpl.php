<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <h3 class="faq__title"><?php print $title; ?></h3>
  
  <?php print render($content['body']); ?>


</article>
