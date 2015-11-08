<?php

class BlogEntryMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['created'] = array(
      'label' => t("Created"),
      'description' => t("The date the entry was created."),
      'type' => 'date',
      'field_type' => 'textfield',
      'schema field' => 'created',
      'setter callback' => 'entity_property_verbatim_set',
      'getter callback' => 'entity_property_verbatim_date_get',
    );
    $properties['updated'] = array(
      'label' => t("Updated"),
      'description' => t("The date the entry was updated."),
      'type' => 'date',
      'schema field' => 'updated',
      'setter callback' => 'entity_property_verbatim_set',
      'getter callback' => 'entity_property_verbatim_date_get',
    );
    $properties['author'] = array(
      'label' => t("Author entity"),
      'type' => 'user',
      'description' => t("The author of the entry."),
      'schema field' => 'author_uid',
      'required' => TRUE,
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
    );

    return $info;
  }

}
