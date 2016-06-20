<?php
/**
 * Implements hook_form_system_theme_settings_alter() function.
 */
function ucrlib_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL) {
  if (isset($form_id)) {
   return;
  }

  $form['minified_assets'] = array(
    '#type' => 'fieldset',
    '#title' => t('Minified CSS/JS'),
    '#description' => t('If turned on, minified css and/or js will be used.
      Otherwise, un-minified css/js will be used. RECOMMENDATION: production
      sites should have both of these options turned on.'),
    '#weight' => -50,
  );

  $form['minified_assets']['ucrlib_minified_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use minified CSS'),
    '#default_value' => theme_get_setting('ucrlib_minified_css'),
    '#ajax' => array(
      'callback' => 'ucrlib_ajax_settings_save',
    ),
  );

  $form['minified_assets']['ucrlib_minified_js'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use minified JS'),
    '#default_value' => theme_get_setting('ucrlib_minified_js'),
    '#ajax' => array(
      'callback' => 'ucrlib_ajax_settings_save',
    ),
  );

}

/**
 * Callback function for theme settings form.
 */
function ucrlib_ajax_settings_save($form, $form_state) {
  $theme = $form_state['build_info']['args'][0];
  $theme_settings = variable_get('theme_' . $theme . '_settings', array());
  $trigger = $form_state['triggering_element'] ['#name'];

  $theme_settings[$trigger] = $form_state['input'][$trigger];

  if (empty($theme_settings[$trigger])) {
    $theme_settings[$trigger] = 0;
  }
  variable_set('theme_' . $theme . '_settings', $theme_settings);
}
