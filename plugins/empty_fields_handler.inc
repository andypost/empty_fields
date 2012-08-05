<?php
/**
 * @file
 * Contains the base class for emptyFieldHandlers
 */

/**
 * Abstract base class defining a field_empty_handler.
 *
 * Defines a way to easily create empty field reaction plugins.
 *
 * @see field_empty_handler_text.
 */
abstract class EmptyFieldHandler {
  public $title;
  public $description;
  public $options;

  /**
   * Create a new EmptyFieldHandler.
   */
  public function __construct() {
    $this->options = $this->defaults();
  }

  /**
   * Declare default options.
   */
  abstract public function defaults();

  /**
   * Provide options to configure content.
   */
  abstract public function form(&$form_state);

  /**
   * Provide Summary text.
   */
  abstract public function summaryText();

  /**
   * Provide a reaction. Set the content of the field.
   */
  abstract public function react($context);

  /**
   * Provide a method to alter the output of the plugin. This is optional.
   */
  public function alterOutput(&$output, $context) {

  }

}
