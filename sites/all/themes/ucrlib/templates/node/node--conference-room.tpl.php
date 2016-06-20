<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="conference-room__content">

    <h2 class="conference-room__title"><?php print $title; ?></h2>

    <?php if (isset($description)) { ?>
      <div class="conference-room__description">
        <?php print $description; ?>
      </div>
    <?php } ?>

    <table class="conference-room__attributes">
      <tbody>
        <?php if (isset($hours)) { ?>
          <tr>
            <th><?php print t('Hours'); ?></th>
            <td><?php print $hours; ?></td>
          </tr>
        <?php } ?>
        <?php if (isset($capacities)) { ?>
          <tr>
            <th><?php print t('Capacity'); ?></th>
            <td><?php print $capacities; ?></td>
          </tr>
        <?php } ?>
        <?php if (isset($equipment)) { ?>
          <tr>
            <th><?php print t('Equipment'); ?></th>
            <td><?php print $equipment; ?></td>
          </tr>
        <?php } ?>
        <?php if (isset($cost)) { ?>
          <tr>
            <th><?php print t('Cost'); ?></th>
            <td><?php print $cost; ?></td>
          </tr>
        <?php } ?>
      </tbody>
    </table>

  </div>


  <aside class="conference-room__sidebar-second">

    <?php print render($content['field_image']); ?>

    <?php if (isset($link)) { ?>
      <a href="<?php print $link; ?>" class="conference-room__reserve-room-button"><?php print t('Reserve This Room'); ?></a>
    <?php } ?>

  </aside>


</article>
