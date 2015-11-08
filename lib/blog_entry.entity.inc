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

  public function __construct(array $values = array()) {
    parent::__construct($values, 'blog_entry');
    if (!$this->entry_id) {
      global $user;
      $this->created = REQUEST_TIME;
      $this->author_uid = $user->uid;
    }
  }

  /**
   * Override buildContent() to add properties.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    $wrapper = entity_metadata_wrapper('blog_entry', $this);
    $author = $wrapper->author->value();

    $content['author'] = array(
      '#theme' => 'blog_entry_property_field',
      '#label' => t('Author'),
      '#items' => array(
        array(
          '#markup' => $author->name,
        ),
      ),
      '#classes' => 'field field-label-inline clearfix',
    );

    $content['created'] = array(
      '#theme' => 'blog_entry_property_field',
      '#label' => t('Created'),
      '#items' => array(
        array(
          '#markup' => format_date($this->created),
        ),
      ),
      '#classes' => 'field field-label-inline clearfix',
    );

    return entity_get_controller($this->entityType)
      ->buildContent($this, $view_mode, $langcode, $content);
  }

  /**
   * Permanently saves the entity.
   *
   * @return bool
   *  Returns FALSE if entity was not saved.
   */
  public function save() {
    $this->updated = REQUEST_TIME;
    return parent::save();
  }

  /**
   * Change the default URI from default/id to blog/entry/id
   */
  protected function defaultUri() {
    return array('path' => 'blog/entry/' . $this->identifier());
  }
}
