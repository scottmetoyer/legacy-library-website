<?php
/**
 * @file
 * quicktabs_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function quicktabs_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}
