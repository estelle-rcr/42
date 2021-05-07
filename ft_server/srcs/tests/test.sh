#!/bin/sh

service mysql start

echo "CREATE DATABASE testdb;" | mysql -u root
echo "CREATE USER 'test'@'localhost';" | mysql -u root
echo "SET password FOR 'test'@'localhost' = password('password');" | mysql -u root
echo "GRANT ALL ON testdb.* TO 'test'@'localhost' IDENTIFIED BY 'password' WITH GRANT OPTION;" | mysql -u root
echo "FLUSH PRIVILEGES" | mysql -u root

echo "CREATE TABLE testdb.todo_list (item_id INT AUTO_INCREMENT, content VARCHAR(255), PRIMARY KEY(item_id));" | mysql -u root

echo "INSERT INTO testdb.todo_list (content) VALUES ('Name');" | mysql -u root
echo "INSERT INTO testdb.todo_list (content) VALUES ('Firstname');" | mysql -u root
echo "INSERT INTO testdb.todo_list (content) VALUES ('Email');" | mysql -u root
echo "INSERT INTO testdb.todo_list (content) VALUES ('Address');" | mysql -u root

echo "SELECT * FROM testdb.todo_list;" | mysql -u root

echo -e "to clean after: \n'mysql -u root'\n'DROP DATABASE testdb;'\n'DROP USER test;'"
