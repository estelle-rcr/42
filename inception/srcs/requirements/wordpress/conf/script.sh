#!/bin/bash

print_success()
{
	echo "[SUCCESS WORDPRESS]"
}

print_fail()
{
	echo "[FAIL WORDPRESS]"
}

cd /var/www/html

i=0
while [ $i -le 60 ]
do
	if mysqladmin -h $WP_DB_HOST ping &> /dev/null
	then
		wp core download --allow-root &&
		wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_USER_PWD --dbhost=$WP_DB_HOST --allow-root &&
		wp core install --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN_USERNAME --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root &&
		wp user create $WP_USER_NAME $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD --allow-root &&
		chmod 644 wp-config.php &&
		wp theme activate twentytwentytwo --allow-root && print_success || print_fail
		break
	else
		sleep 1
	fi
	((i++))
done

exec php-fpm7.3 -F -R
