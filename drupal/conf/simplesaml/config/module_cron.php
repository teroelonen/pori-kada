<?php
/*
 * Configuration for the Cron module.
 */

$config = [
    'key' => getenv('SAML_ADMINPASS'),
    'allowed_tags' => ['daily', 'hourly', 'frequent'],
    'debug_message' => true,
    'sendemail' => true,
];
