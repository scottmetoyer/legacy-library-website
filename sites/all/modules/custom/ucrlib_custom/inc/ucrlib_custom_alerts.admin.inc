<?php

/**
 * Admin form for alert settings.
 */
function ucrlib_custom_alert_settings() {
  $form['ucrlib_custom_alert_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable sitewide alert?'),
    '#default_value' => variable_get('ucrlib_custom_alert_enabled', FALSE),
  );

  $form['ucrlib_custom_alert_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Alert text'),
    '#default_value' => variable_get('ucrlib_custom_alert_text', ''),
    '#size' => 60,
    '#maxlength' => 255,
  );

  return system_settings_form($form);
}
