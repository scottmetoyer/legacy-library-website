<?php
/**
 * @file
 * news_views_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function news_views_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function news_views_feature_image_default_styles() {
  $styles = array();

  // Exported image style: news_list_featured.
  $styles['news_list_featured'] = array(
    'label' => 'News list featured (435x326)',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 435,
          'height' => 326,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: news_list_home_thumb.
  $styles['news_list_home_thumb'] = array(
    'label' => 'News list homepage thumb (60x60)',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: news_list_thumb.
  $styles['news_list_thumb'] = array(
    'label' => 'News list thumb (110x110)',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 110,
          'height' => 110,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
