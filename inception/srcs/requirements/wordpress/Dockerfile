FROM debian:buster

RUN	apt-get update && \
	apt-get -y install php7.3-fpm php7.3-common php7.3-mysql \
	curl mariadb-client && \
	mkdir -p /var/www/html && \
	mkdir -p /run/php/ && \
	chown -R www-data:www-data /var/www/html && \
	chown -R www-data:www-data /run/php/


RUN  curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./conf/script.sh root/conf/script.sh

CMD ["./root/conf/script.sh"]
