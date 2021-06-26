# Pori project

## Environment variables

- `WKV_SITE_ENV` - environment name
- `DB_PASS_DRUPAL` - database password
- `DB_USER_DRUPAL` - database username
- `DB_HOST_DRUPAL` - database host
- `DB_NAME_DRUPAL` - database name
- `WARDEN_TOKEN` - shared security token between the site and Warden server
- `SAML_ADMINPASS` - SimpleSAML administration password
- `SAML_SECRETSALT` - SimpleSAML salt hash
- `XDEBUG_MODE` - Xdebug mode
- `PHP_IDE_CONFIG` - Xdebug setting for PhpStorm

## SimpleSAML

- Login path: <https://pori.fi/login_ad>
- Admin path: <https://pori.fi/simplesaml>

## Local environment

### [Setup](https://docs.lando.dev/basics/installation.html)

1. Install the [latest Lando](https://github.com/lando/lando/releases) and read the [documentation](https://docs.lando.dev/).
2. Check out the repo and go to the project root: `git clone git@github.com:City-of-Pori/pori-kada.git pori && cd pori/drupal`.
3. Run `lando start`.
4. Compile the themes with `lando compile`.
5. Import data with `lando syncdb` (staging environment) or `lando syncdb prod` (production). Register your public key and connect to the required VPN first.
6. Run `lando update` to update database, revert the features and enable development modules.

### Local sites with drush site aliases

- <https://pori.lndo.site>, alias `@pori.local`,
- <https://businesspori.lndo.site>, alias `@pori.b.local`,
- <https://visitpori.lndo.site>, alias `@pori.v.local`.

### Production sites

- <https://www.pori.fi/>, `@pori.prod`,
- <https://www.businesspori.fi/>, `@pori.b.prod`,
- <https://www.visitpori.fi/>, `@pori.v.prod`.

### [Services](https://docs.lando.dev/config/services.html)

- <http://pori-adminer.lndo.site> - [Adminer](https://hub.docker.com/r/dehy/adminer/) for database management, log in **without** entering the credentials.
- <http://pori-mail.lndo.site> - [MailHog](https://docs.lando.dev/config/mailhog.html) for mail management.

### [Tools](https://docs.lando.dev/config/tooling.html)

Full commands/tools overview is available by running `lando`. Custom tools:

- `lando build` - build the local site.
- `lando compile` - compile the themes.
- `lando npm`, `lando bower`, `lando gulp` - run frontend commands.
- `lando phpcs`, `lando phpcbf`- use PHP_CodeSniffer:
  - Use Drupal & DrupalPractice standard for selected extensions: `lando phpcs --standard=Drupal,DrupalPractice web/sites/all/modules/contrib --extensions=php,inc,module,install`
  - Check `web/sites/all/modules/custom` folder for PHP 7.2 compatibility using [PHPCompatibility](https://github.com/PHPCompatibility/PHPCompatibility) standard: `lando phpcs --standard=PHPCompatibility --extensions=php,inc,module,install --report-full=report_72.txt --runtime-set testVersion 7.2 -ps web/sites/all/modules/custom`.
- `lando syncdb <remote>` - synchronize local database with selected remote environment. Options: `stage` (default), `prod`.
- `lando update` - apply required (database) updates.
- `lando xdebug <mode>` - load [Xdebug](https://xdebug.org/) in the selected [mode(s)](https://xdebug.org/docs/all_settings#mode).

### Theming

Themes can be compiled by using `lando compile`. See also `drupal/.lando/node.sh` & [drupal/web/sites/all/themes/custom/kada/README.md](drupal/web/sites/all/themes/custom/kada/README.md).

### Workflow

Note: We use [Wunderflow](http://wunderflow.wunder.io/) as our git workflow.

All new features must be based on the `master` branch.
All hotfixes must be based on the `production` branch.
The `develop` branch is used only for testing and must never be merged back to master.

### Developer notes

- Restart Docker Desktop when facing constant `COMPOSE_HTTP_TIMEOUT` errors during `lando rebuild`.

### Provisioning

Perform the following tasks **in the project root folder** to set up the Lando-based provisioning tool:

1. create the `ansible.vault` file and save it with the Ansible vault password (`Pori ansible-vault key` in LastPass),
2. run `lando start`.

Usage: `lando provision [-t|s ANSIBLE_TAGS] [ENVIRONMENT]`.

```sh
 -t ANSIBLE_TAGS       Ansible tags to be provisioned.
 -s ANSIBLE_TAGS       Ansible tags to be skipped when provisioning.
    ENVIRONMENT        Environment to be provisioned.
```

Example of provisioning `nginx` Ansible tag in a `develop` environment: `lando provision -t nginx develop`.
