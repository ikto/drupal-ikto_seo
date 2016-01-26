<?php

function ikto_seo_admin_settings_form($form, &$form_state) {

  $form['adjustments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Adjustments'),
    '#description' => t('These adjustments will work only for anonymous users.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['adjustments']['ikto_seo_redirect_home'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent to visit homepage with internal path'),
    '#description' => t('If you try to open "@src", you will be redirected to "@dest".', array(
      '@src' => url(variable_get('site_frontpage', 'node'), array('absolute' => TRUE)),
      '@dest' => url('<front>', array('absolute' => TRUE)),
    )),
    '#default_value' => variable_get('ikto_seo_redirect_home', FALSE),
  );

  $form['adjustments']['ikto_seo_redirect_internal_path'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent to visit pages with internal path if they have aliases'),
    '#default_value' => variable_get('ikto_seo_redirect_internal_path', FALSE),
  );

  if ($example = ikto_seo_get_internal_path_redirect_example()) {
    $form['adjustments']['ikto_seo_redirect_internal_path']['#description'] = t('If you try to open "@src", you will be redirected to "@dest".', array(
      '@src' => url($example['source'], array('absolute' => TRUE, 'alias' => TRUE)),
      '@dest' => url($example['alias'], array('absolute' => TRUE)),
    ));
  }

  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['options']['ikto_seo_use_redirect'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use redirect module if possible'),
    '#default_value' => variable_get('ikto_seo_use_redirect'),
  );

  return system_settings_form($form);
}
