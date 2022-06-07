#!/bin/bash

print_success()
{
	echo "[SUCCESS CREATING DB]"
}

print_fail()
{
	echo "[FAIL CREATING DB]"
}

# If the files from mysqld service doesn't exist then launch mysqld in safe mode in background
if [ ! -d /var/run/mysqld/mysqld.sock ]
then
	mysqld &
fi

i=0
while [ $i -le 60 ]
do
	if mysqladmin ping &> /dev/null
	then
		mysql -u root -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;" &&
		mysql -u root -e "DELETE FROM mysql.user WHERE user='root';" &&
		mysql -u root -e "CREATE USER '$MYSQL_ADMIN'@'%' IDENTIFIED BY '$MYSQL_ADMIN_PWD';" &&
		mysql -u root -e "GRANT ALL ON *.* TO '$MYSQL_ADMIN'@'%';" &&
		mysql -u root -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PWD';" &&
    	mysql -u root -e "GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';" &&
		mysql -u root -e "FLUSH PRIVILEGES;" &&
		mysqladmin shutdown -u$MYSQL_ADMIN -p$MYSQL_ADMIN_PWD && print_success || print_fail
		break
	else
		sleep 1
	fi
	((i++))
done


mysqld
