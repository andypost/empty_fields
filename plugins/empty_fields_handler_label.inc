<?php
/**
 * @file
 * Contains the EntityLabelEmptyFieldHandler plugin for Empty Fields module.
 */

/**
 * Defines EntityLabelEmptyFieldHandler.
 */
class EntityLabelEmptyFieldHandler extends EmptyFieldHandler {

  /**
   * Implementation of EmptyFieldText::defaults().
   *
   * @return array
   *   An array of default_values for the form below. Key names must match.
   */
  public function defaults() {
    return array(
      'display' => 'text',
    );
  }

  /**
   * Implementation of EmptyFieldText::form().
   *
   * @return array
   *   A FAPI array to be used in configuration of this empty text plugin.
   */
  public function form($context) {
    $form['display'] = array(
      '#type' => 'radios',
      '#title' => t('Display options'),
      '#default_value' => isset($this->options['display']) ? $this->options['display'] : 'text',
      '#options' => array(
        'text' => t('Text only'),
        'link' => t('Link'),
      ),
      '#required' => TRUE,
    );

    return $form;
  }

  /**
   * Implementation of EmptyFieldText::react().
   *
   * @return string
   *   A rendered string of html for display.
   */
  public function react($context) {
    $title = entity_label($context['entity_type'], $context['entity']);
    switch ($this->options['display']) {
      case 'link':
        if ($url = entity_uri($context['entity_type'], $context['entity'])) {
          return l($title, $url['path'], $url['options']);
        }
        // Fall through...

      case 'text':
      default:
        return check_plain($title);
    }
  }

  /**
   * Implementation of EmptyFieldText:summaryText().
   *
   * @return string
   *   Text for the field formatter settings summary.
   */
  public function summaryText() {
    switch ($this->options['display']) {
      case 'link':
        return t('Uses entity link if empty');

      case 'text':
      default:
        return t('Uses entity label if empty');
    }
  }
}
