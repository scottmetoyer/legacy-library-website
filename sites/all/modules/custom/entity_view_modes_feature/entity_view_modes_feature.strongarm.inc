<?php
/**
 * @file
 * entity_view_modes_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function entity_view_modes_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'node' => array(
      'teaser2' => array(
        'label' => 'Teaser2',
        'custom settings' => 1,
      ),
      'teaser3' => array(
        'label' => 'Teaser3',
        'custom settings' => 1,
      ),
      'map' => array(
        'label' => 'Map',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  return $export;
}
