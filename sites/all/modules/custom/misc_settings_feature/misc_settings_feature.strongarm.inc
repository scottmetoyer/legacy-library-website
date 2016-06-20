<?php
/**
 * @file
 * misc_settings_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function misc_settings_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = 'node/[node:nid]';
  $export['pathauto_node_pattern'] = $strongarm;

  return $export;
}
