#!/bin/sh
set -exu

# Symlink the site aliases file.
mkdir -p ~/.drush
ln -sf /app/drush/pori.aliases.drushrc.php ~/.drush/pori.aliases.drushrc.php

# Create a private files directory.
mkdir -p /app/web/sites/default/files/private

# SimpleSAML configuration.
cd /app
# https://simplesamlphp.org/docs/stable/metarefresh:simplesamlphp-automated_metadata
echo >"vendor/simplesamlphp/simplesamlphp/modules/cron/enable"
echo >"vendor/simplesamlphp/simplesamlphp/modules/metarefresh/enable"
php vendor/simplesamlphp/simplesamlphp/modules/cron/bin/cron.php -t hourly
chown -R www-data:www-data vendor/simplesamlphp/simplesamlphp/metadata/metarefresh-pori
