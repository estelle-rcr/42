FROM debian:buster

RUN apt-get -y update && apt-get -y install mariadb-server \
	wget \
	php \
	php-cli \
	php-cgi \
	php-mbstring \
	php-fpm \
	php-mysql \
	nginx

COPY srcs/setup.sh srcs/index_switch.sh /tmp/
COPY srcs/config/ /tmp/
COPY srcs/tests /tmp/tests

ENV AUTOINDEX on

EXPOSE 80 443

CMD bash /tmp/setup.sh