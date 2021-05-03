#!/bin/bash

mkdir /var/www/localhost

chown -R $USER:$USER /var/www/localhost

cp setup_index_on /etc/nginx/sites-available/localhost
ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost

cp -r phpMyAdmin /var/www/localhost/phpMyAdmin

service nginx reload
service nginx start
service nginx status


