Empty fields module - http://drupal.org/sandbox/aland/1658254
=============================================================

DESCRIPTION
------------
This module provides a way to show fields that are empty by new display
formatter settings. These can be either an empty tag, "<none>" or custom
text defined by the field administrator.

REQUIREMENTS
------------
Drupal 7.x
Field formatter settings - http://drupal.org/project/field_formatter_settings

INSTALLATION
------------
1.  Place the Empty Fields modules into your modules directory.
    This is normally the "sites/all/modules" directory.
    Also download and place the Field formatter settings module here to 
    http://drupal.org/project/field_formatter_settings
    

2.  Go to admin/build/modules. Enable the modules.
    The Empty Fields modules is found in the Fields section.

Read more about installing modules at http://drupal.org/node/70151

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

REFERENCES
----------

Andrew Macpherson - http://drupal.org/user/265648
Everett Zufelt - http://drupal.org/user/406552
Dave Reid - http://drupal.org/user/53892
Field Delimiter - http://drupal.org/project/field_delimiter
Field formatter settings - http://drupal.org/project/field_formatter_settings