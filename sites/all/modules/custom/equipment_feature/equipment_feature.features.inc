<?php
/**
 * @file
 * equipment_feature.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function equipment_feature_image_default_styles() {
  $styles = array();

  // Exported image style: equipment.
  $styles['equipment'] = array(
    'label' => 'Equipment (270x200)',
    'effects' => array(
      18 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
