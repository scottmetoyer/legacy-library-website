<?php
/**
 * @file
 * User functions.
 */

/**
 * Implements hook_block_view_MODULE_DELTA_alter().
 */
function ucrlib_block_view_user_login_alter(&$data, $block) {
  global $user;
  // Always make the user login block visible if not logged in.
  if (!$user->uid) {
    $block->subject = t('User login');
    $block->content = drupal_get_form('user_login_block');
  }
}
