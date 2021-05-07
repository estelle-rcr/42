#!/bin/bash

mkdir /var/www/localhost

# TESTS index.html & info.php & database (uncomment for use but /!\ index.html)
#cp /tmp/tests/* /var/www/localhost
#./tmp/tests/test.sh

# setup server config
if [ $AUTOINDEX = "on" ]
then 
	cp /tmp/nginx_config_on /etc/nginx/sites-available/localhost ;
elif [ $AUTOINDEX = "off" ]
then 
	cp /tmp/nginx_config_off /etc/nginx/sites-available/localhost ;
	cp /var/www/html/index.nginx-debian.html /var/www/localhost/index.html
fi

ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost
rm -r /etc/nginx/sites-enabled/default

# setup wordpress
wget http://fr.wordpress.org/latest-fr_FR.tar.gz -P /tmp/
tar -xzvf /tmp/latest-fr_FR.tar.gz -C /var/www/localhost
mv /tmp/wp-config.php /var/www/localhost/wordpress/wp-config.php

# setup phpMyAdmin
mkdir /var/www/localhost/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz -P /tmp/
tar -xzvf /tmp/phpMyAdmin-4.9.0.1-all-languages.tar.gz -C /tmp
mv /tmp/phpMyAdmin-4.9.0.1-all-languages/* /var/www/localhost/phpmyadmin
mv /tmp/config.inc.php /var/www/localhost/phpmyadmin

# change rights for all users to access the pages
chmod -R 755 /var/www/

#SSL certificate
openssl req -newkey rsa:4096 -x509 -sha256 -nodes -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.csr -subj "/C=FR/ST=IDF/L=Paris/O=42Paris/OU=student/CN=erecuero"

# setup mySQL for granting access to user 'wordpress'
service mysql start
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "CREATE USER 'wordpress'@'localhost';" | mysql -u root
echo "SET password FOR 'wordpress'@'localhost' = password('password');" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

# start nginx & php & bash command line & process never sleep
service nginx start
service nginx status
/etc/init.d/php7.3-fpm start
/etc/init.d/php7.3-fpm status
bash
sleep infinity
