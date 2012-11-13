<?php

/**
 * @file
 * Documents Block reference's hooks for api reference.
 */

/**
 * Alter the potential references.
 *
 * @param $references
 *  The references array to be modified.
 * @param $field
 *  Array containing field data.
 * @param $return_full_blocks
 *  Whether to return full blocks.
 * @param $string
 *  Filter string to match blocks.
 * @param $exact_string
 *  Strictly match string like for validation.
 */
function hook_blockreference_potential_references_alter(&$references, $field, $current_bids = array(), $return_full_blocks = FALSE, $string = '', $exact_string = FALSE) {
  // no example code
}
