FROM 	debian:buster

RUN 	apt-get update && apt-get install -y nginx \
		openssl \
		; openssl req -newkey rsa:4096 -x509 -sha256 -nodes -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.csr -subj "/C=FR/ST=None/L=Paris/O=42Paris/OU=student/CN=erecuero" \
		; chown -R www-data:www-data /var/www/html \
		;	rm /etc/nginx/sites-enabled/default \
		; mkdir -p /var/www/erecuero.42.fr && chown -R www-data:www-data /var/www/erecuero.42.fr

COPY	./conf/nginx.conf /etc/nginx/nginx.conf

CMD [ "nginx", "-g", "daemon off;" ]