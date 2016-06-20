<?php

/**
 * Admin form for image settings.
 */
function ucrlib_custom_images_settings() {
  $form['homepage'] = array(
    '#type' => 'fieldset',
    '#title' => t('Homepage banner image'),
    '#description' => t('Image should be at least 1500px X 400px and will be cropped to size.'),
  );

  // If there is already an uploaded image display the image here.
  if ($image_fid = variable_get('ucrlib_custom_banner_image', FALSE)) {
    $image = file_load($image_fid);
    $form['homepage']['image'] = array(
      '#markup' => theme('image_style', array(
        'path' => $image->uri,
        'style_name' => 'thumbnail',
      )),
    );
  }

  // Use the #managed_file FAPI element to upload an image file.
  $form['homepage']['ucrlib_custom_banner_image'] = array(
    '#type' => 'managed_file',
    '#title' => t('Homepage banner image'),
    '#default_value' => variable_get('ucrlib_custom_banner_image', ''),
    '#description' => t("The uploaded image will be used as the banner on the homepage."),
    '#upload_location' => 'public://homepage-banner/',
    '#upload_validators' => array(
      'file_validate_extensions' => array(
        'gif png jpg jpeg',
      ),
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'ucrlib_custom') . '/ucrlib_custom.css',
  );

  return $form;
}

/**
 * Submit handler for ucrlib_custom_images_settings().
 */
function ucrlib_custom_images_settings_submit($form, &$form_state) {

  // If fid is not 0 we have a valid file.
  if ($form_state['values']['ucrlib_custom_banner_image'] != 0) {

    // The new file's status is set to 0 or temporary and in order to ensure
    // that the file is not removed after 6 hours we need to change it's status
    // to 1. Save the ID of the uploaded image for later use.
    $file = file_load($form_state['values']['ucrlib_custom_banner_image']);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);

    // When a module is managing a file, it must manage the usage count.
    // Here we increment the usage count with file_usage_add().
    file_usage_add($file, 'ucrlib_custom', 'default_image', 1);

    // Save the fid of the file so that the module can reference it later.
    variable_set('ucrlib_custom_banner_image', $file->fid);
    drupal_set_message(t('The form has been submitted and the image has been saved, filename: @filename.', array(
      '@filename' => $file->filename,
    )));
  }

  // If the file was removed we need to remove the module's reference to the
  // removed file's fid, and remove the file.
  elseif ($form_state['values']['ucrlib_custom_banner_image'] == 0) {

    // Retrieve the old file's id.
    $fid = variable_get('ucrlib_custom_banner_image', FALSE);
    $file = $fid ? file_load($fid) : FALSE;
    if ($file) {

      // When a module is managing a file, it must manage the usage count.
      // Here we decrement the usage count with file_usage_delete().
      file_usage_delete($file, 'ucrlib_custom', 'default_image', 0);

      // The file_delete() function takes a file object and checks to see if
      // the file is being used by any other modules. If it is the delete
      // operation is cancelled, otherwise the file is deleted.
      file_delete($file);
    }

    // Either way the module needs to update it's reference since even if the
    // file is in use by another module and not deleted we no longer want to
    // use it.
    variable_set('ucrlib_custom_banner_image', FALSE);
    drupal_set_message(t('The image @image_name was removed.', array(
      '@image_name' => $file->filename,
    )));
  }
}
