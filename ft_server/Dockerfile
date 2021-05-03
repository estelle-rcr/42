FROM debian:buster

#RUN apt-get update && apt-get upgrade
RUN apt-get update && apt-get install -y \
	nginx \
	mariadb-server \
	wget \
	php \
	php-fpm \
	php-mysql
	&& systemctl start mariadb

COPY srcs ./root/

WORKDIR /root/

CMD bash setup.sh
#sudo apt-get install docker-ce docker-ce-cli containerd.io
#  && curl -fsSL https://get.docker.com -o get-docker.sh
#service nginx stop
#libnss3-tools


