<?php

/**
 * @file
 * Blog Entry UI controller providing admin UI.
 */
class BlogEntryUIController extends EntityDefaultUIController {
  /**
   * Overrides the EntityDefaultUIController to sort by date DESC
   * @param $conditions
   *   An array of conditions as needed by entity_load().
   * @return Array
   *   A renderable array.
   */
  public function overviewTable($conditions = array()) {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $this->entityType)
      ->propertyOrderBy('created', 'DESC');

    // Add all conditions to query.
    foreach ($conditions as $key => $value) {
      $query->propertyCondition($key, $value);
    }

    $query->pager(10);

    $results = $query->execute();

    $ids = isset($results[$this->entityType]) ? array_keys($results[$this->entityType]) : array();
    $entities = $ids ? entity_load($this->entityType, $ids) : array();

    $rows = array();
    foreach ($entities as $entity) {
      $rows[] = $this->overviewTableRow($conditions, entity_id($this->entityType, $entity), $entity);
    }

    $render = array(
      '#theme' => 'table',
      '#header' => $this->overviewTableHeaders($conditions, $rows),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }
}
