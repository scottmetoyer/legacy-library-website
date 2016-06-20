<?php
/**
 * @file
 * exhibits_views_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function exhibits_views_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function exhibits_views_feature_image_default_styles() {
  $styles = array();

  // Exported image style: exhibits_list.
  $styles['exhibits_list'] = array(
    'label' => 'Exhibits list (270x200)',
    'effects' => array(
      20 => array(
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
