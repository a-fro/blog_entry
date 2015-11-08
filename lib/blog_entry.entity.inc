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

  /**
   * Change the default URI from default/id to blog/entry/id
   */
  protected function defaultUri() {
    return array('path' => 'blog/entry/' . $this->identifier());
  }
}
