FROM 	debian:buster

RUN 	apt-get update && apt-get install -y apt-utils mariadb-server \
		mariadb-client && mkdir -p /var/run/mysqld && mkdir -p /run/mysqld && \
		chown -R mysql:root /run/mysqld && chown -R mysql:root /var/run/mysqld

COPY	./conf/script.sh root/conf/script.sh
COPY	./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

CMD ["./root/conf/script.sh"]
