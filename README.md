# Pori project

## Local environment with Lando

### Setup

1. Install the latest [Lando](https://docs.lando.dev/basics/installation.html) and read the [documentation](https://docs.lando.dev/).
2. Setup your public key: <https://key.wunder.io> and/or <https://www.ssh.com/ssh/copy-id>.
3. Check out the repo and go to the project root: `git clone git@github.com:City-of-Pori/pori-kada.git pori && cd pori/drupal`
4. Start the site by running `lando start`.
5. Import data:
   1. `lando syncdb <env>` ([set up your public key](https://key.wunder.io) first if needed) or
   2. `lando db-import <dumpfile>`.

### Sites

- <https://pori.lndo.site>
- <https://businesspori.lndo.site>
- <https://visitpori.lndo.site>

### Services

- <https://pori-adminer.lndo.site> - Adminer for database management, log in **without** entering the credentials.
- <https://pori-mail.lndo.site> - Mailhog for mail management.
- <https://pori-solr.lndo.site> - Solr for data indexing.

### Tools

Full commands/tools overview is available at `lando`. Custom tools:

- `lando build.sh` - use `build.sh`. `lando build.sh update lando` updates makefile changes.
- `lando npm` - use npm
- `lando syncdb <env>` - synchronise local database with selected environment (`stage` by default, `prod`)
- `lando update` - update database & enable develpoment components

## Local environment with Vagrant

Fire up the vagrant environment

```sh
vagrant up
```

If all goes well you can proceed to creating a new build.

Make sure drupal/files directory exists.If not create manually

```sh
vagrant ssh
cd /vagrant/drupal
./build.sh new
```

Synchronise the database from production.

```sh
cd .. && ./syncdb.sh
```

If you run into issues during this step, import database manually (get from server, auth from LastPass) and run

```sh
./build.sh update
```

When you're done, navigate to <https://local.pori.fi>

## Developer notes

### General information

Note: We use [Wunderflow](http://wunderflow.wunder.io/) as our git workflow.

All new features must be based on the `master` branch.
All hotfixes must be based on the `production` branch.
The `develop` branch is used only for testing and must never be merged back to master.

Tip: You can use drush aliases to execute drush commands without loggin into the servers or vagrant box. For example `drush @pori.local cc css-js`.

### Folder structure

```sh
├── ansible                 (Cloned) Ansible roles common for all environments.
├── ansible.cfg             Ansible configurations.
├── build.sh                Wundertools environment buildscript.
├── CHANGELOG               Wundertools environment changelog.
├── conf                    Different environment provisioning configs.
├── docs                    Developer documentation.
├── drupal  
│   ├── builds              Folder containing previous builds.           
│   ├── build.sh            Main site build script.
│   ├── code                Custom code including custom modules, features and themes.
│   ├── conf                Different build configurations.
│   ├── files               Drupal files.
│   ├── scripts             Scripts for handling integrations with 3rd party systems.
│   ├── translations        Exported translations.
│   ├── web                 Current build.                  
├── current                 Link to the latest build directory.
├── local_ansible_roles     Custom ansible roles.
├── provision.sh            Utility script for handling provision of different enviroments.
├── README.md               Generic readme file (this file)
├── DEPLOYMENTS.md          Instructions about deployments.  
├── secrets                 Encrypted passwords and API keys for ansible playbooks.  
├── syncdb_local.sh         Helper script included in the main sync script.
├── syncdb.sh               Database sync script.
├── tests                   Tests
├── Vagrantfile             Vagrant environt entry point.
└── VERSION                 File specifying the current Wundertools version in use.
```
