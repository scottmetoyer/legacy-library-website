<?php
/**
 * @file
 * entity_view_modes_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function entity_view_modes_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
