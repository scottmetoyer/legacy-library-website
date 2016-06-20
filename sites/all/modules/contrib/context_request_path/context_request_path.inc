<?php

/**
 * @file
 * The class for the context request path conditions
 */

/**
 * Expose request paths as a context condition. Inherits from Condition Path
 */
class ContextRequestPath extends context_condition_path {

  /**
   * Execute condition and check for matches.
   */
  public function execute() {

    // We only execute this code if the condition is enabled.
    if ($this->condition_used()) {

      // Split request path into parts to match.
      $current_path = array(trim(request_path(), '/'));

      // Loop through the parts.
      foreach ($this->get_contexts() as $context) {

        // Get the condition values.
        $paths = $this->fetch_from_context($context, 'values');

        // Match path condition value.
        if ($this->match($current_path, $paths, TRUE)) {

          // Condition met, let context know.
          $this->condition_met($context);
        }
      }
    }
  }
}
