Empty fields module - http://drupal.org/sandbox/aland/1658254
=============================================================

DESCRIPTION
------------
This module provides a way to show fields that are empty by new display
formatter settings. These can be either custom text defined by the field
administrator or the return value of a defined callback.

REQUIREMENTS
------------
Drupal 7.x
Field formatter settings - http://drupal.org/project/field_formatter_settings

INSTALLATION
------------
1.  Place the Empty Fields modules into your modules directory.
    This is normally the "sites/all/modules" directory.
    Also download and place the Field formatter settings module here too.
    http://drupal.org/project/field_formatter_settings


2.  Go to admin/build/modules. Enable the modules.
    The Empty Fields modules is found in the Fields section.

Read more about installing modules at http://drupal.org/node/70151

API
---
For specific use-cases, you can define a custom callback to generate
dynamic content.

Firstly, implement hook_empty_field_callbacks()

<?php
/**
 * Implements hook_empty_field_callbacks().
 */
function hook_empty_field_callbacks() {
  $info['mymodule_datetimes'] = array(
    'label' => t('Date and time summary'),
    'callback' => 'mymodule_empty_datetime_field_callback',
  );
  return $info;
}
?>

Then implement the callback.

<?php
/**
 * Callback defined in hook_empty_field_callbacks().
 */
function mymodule_empty_datetime_field_callback($field_name, $context) {
  return format_date(time());
}
?>

The context has the entity_type, entity, view_mode as well as the empty
field details, field and instance. If the callback returns FALSE or NULL,
the empty field will not be rendered.

This allows for more complex conditional includes:
<?php
/**
 * Callback defined in hook_empty_field_callbacks().
 *
 * This tries to generate a date description if the date description is empty.
 * This description is based off other fields on the node.
 */
function mymodule_empty_datetime_field_callback($field_name, $context) {
  if ($field_name == 'field_date_text' && $context['entity_type'] == 'node') {
    if ($desc = mymodule_get_date_description($context['entity'])) {
      return $desc;
    }
    else {
      // Return FALSE or NULL as we can not calculate the text description.
      return FALSE;
    }
  }
  // If another field, return nothing so that the empty field is not rendered.
}

/**
 * Calculates the text from the field field_dates.
 */
function mymodule_get_date_description($node) {
  if ($items = field_get_items('node', $node, 'field_dates')) {
    return t("We have dates, but we aren't telling you!");
  }
}
?>

ACKNOWLEDGEMENTS
----------------
Core implementation was based of Field Delimiter module by Andrew Macpherson,
(andrewmacpherson) and builds on the base concept started by Everett Zufelt in
a support request at http://drupal.org/node/1283974#comment-5385242.

It is made possible with Dave Reids Field formatter settings module that plugs
a couple of the holes found in the core Drupal Field API.

AUTHORS
-------
Alan D. - http://drupal.org/user/198838
rypit   - http://drupal.org/user/868380

REFERENCES
----------

Andrew Macpherson - http://drupal.org/user/265648
Everett Zufelt - http://drupal.org/user/406552
Dave Reid - http://drupal.org/user/53892
Field Delimiter - http://drupal.org/project/field_delimiter
Field formatter settings - http://drupal.org/project/field_formatter_settings
