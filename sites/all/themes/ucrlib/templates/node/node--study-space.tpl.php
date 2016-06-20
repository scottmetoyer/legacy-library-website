<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="study-space__content">

    <div class="study-space__library-info">
      <span><?php print $library; ?></span> <span>/</span> <span><?php print t('Floor #'); ?><?php print $floor; ?></span>
    </div>
    <h1><?php print $title; ?></h1>

    <?php if (isset($features)) { ?>
      <div class="study-space__type study-space__attribute">
        <h3 class="study-space__attribute-title"><?php print t('Type'); ?></h3>
        <div class="study-space__attribute-content">
          <?php print $features; ?>
        </div>
      </div>
    <?php } ?>
    <?php if (isset($equipment)) { ?>
      <div class="study-space__equipment study-space__attribute">
        <h3 class="study-space__attribute-title"><?php print t('Equipment'); ?></h3>
        <div class="study-space__attribute-content">
          <?php print $equipment; ?>
        </div>
      </div>
    <?php } ?>
    <?php if (isset($capacity)) { ?>
      <div class="study-space__capacity study-space__attribute">
        <h3 class="study-space__attribute-title"><?php print t('Capacity'); ?></h3>
        <div class="study-space__attribute-content">
          <ul class="item-list">
            <li><?php
            	if("1"!=$capacity)
            	{
            		print t('Up to @capacity people', array('@capacity' => $capacity));
            	}
            	else
            	{
            		print t('Up to @capacity person', array('@capacity' => $capacity));
            	}
            ?></li>
          </ul>
        </div>
      </div>
    <?php } ?>

    <?php print render($content['body']); ?>

    <div class="study-space__all-spaces-link">
      <?php print htmlspecialchars_decode($all_study_spaces_link); ?>
    </div>

  </div>


  <aside class="study-space__sidebar-first">

    <?php print render($content['field_image']); ?>

    <?php if (isset($link)) { ?>
      <a href="<?php print $link; ?>" class="study-space__reserve-space-button"><?php print t('Reserve This Space'); ?></a>
    <?php } ?>

  </aside>


</article>
