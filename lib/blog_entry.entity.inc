<?php
/**
 * @file
 * Blog entry entity classes
 */

class BlogEntry extends Entity {

  public
    $entry_id = NULL,
    $title = '',
    $author_uid = NULL,
    $created = '',
    $updated = '';

  /**
   * @todo add properties
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    return parent::buildContent($view_mode, $langcode);
  }
}
