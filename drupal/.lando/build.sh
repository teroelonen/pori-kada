#!/bin/sh
set -exu

# Symlink the site aliases file.
mkdir -p ~/.drush
ln -sf /app/drush/pori.aliases.drushrc.php ~/.drush/pori.aliases.drushrc.php

# Create a private files directory.
mkdir -p /app/web/sites/default/files/private
