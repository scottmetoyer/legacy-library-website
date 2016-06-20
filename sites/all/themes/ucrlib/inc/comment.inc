<?php

/**
 * Implements the hook_preprocess_comment().
 */
function ucrlib_preprocess_comment(&$vars) {
  $vars['user_picture'] = theme_get_setting('toggle_comment_user_picture') ? theme('user_picture', array('account' => $vars['comment'])) : '';
}
