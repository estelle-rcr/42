#!/bin/sh

if ! cmp -s /etc/nginx/sites-enabled/localhost tmp/nginx_config_off
then
	echo "index OFF"
	cp /tmp/nginx_config_off /etc/nginx/sites-available/localhost
	cp /var/www/html/index.nginx-debian.html /var/www/localhost/index.html
	rm /etc/nginx/sites-enabled/localhost
	ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost
elif ! cmp -s /etc/nginx/sites-enabled/localhost tmp/nginx_config_on
then
	echo "index ON"
	rm /var/www/localhost/index.html
	cp /tmp/nginx_config_on /etc/nginx/sites-available/localhost
	rm /etc/nginx/sites-enabled/localhost
	ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost
fi

service nginx reload