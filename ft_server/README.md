# ft_server

## How to start:

### BUILD Docker image (use --no-cache when working on it):  
  `sudo docker build --no-cache -t name .`

### RUN the container:
On the Virtual machine, stop the already ongoing nginx service:  
  `sudo service nginx stop`

  Open the container in 'interactive' mode for testing:  
  `sudo docker run -it -p 80:80 -p 443:443 name`

  Open the container in detach mode:  
  `sudo docker run -d --p 80:80 -p 443:443 name`

  By default, the index is at on, it can be changed to off or on when launching:  
  `sudo docker run -d --p 80:80 -p 443:443 --env=AUTOINDEX=off name`

  It can also be changed when the server is running in interactive mode by executing in the container's command line the index_switch exec at the root:  
  `./index_switch.sh`

### RUN the container:
  `sudo docker system prune`
  OR:
  `sudo docker ps -a`
  `sudo docker rm -f container_name`
  `sudo docker images`
  `sudo docker rmi ID_img`  


## List of resources:

* Understanding the overall Docker technology: https://docs.docker.com/get-started/overview/
* Post-installation steps for Ubuntu (42VM): https://docs.docker.com/engine/install/linux-postinstall/
* How to write a Dockerfile: https://docs.docker.com/develop/develop-images/dockerfile_best-practices/
* Run Docker: https://docs.docker.com/get-started/
* Dockerfile instructions (EXPOSE, ENV...): https://docs.docker.com/engine/reference/builder/
* Basic setup of Nginx, mySQL database & tests: https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mysql-php-lemp-stack-on-ubuntu-20-04-fr
* Start, stop, restart, reload Nginx: https://linuxize.com/post/start-stop-restart-nginx/
* Understanding the requests of servers with Nginx: http://nginx.org/en/docs/http/request_processing.html
* Redirect http to https: https://serversforhackers.com/c/redirect-http-to-https-nginx
* IPv4 and IPv6 : https://stackoverflow.com/questions/34305351/what-does-mean-in-my-nginx-config-file
* OpenSSL certificate: https://www.kinamo.fr/fr/support/faq/comment-generer-une-demande-de-certificat-ssl-csr-avec-openssl
* Use of tar: https://unix.stackexchange.com/questions/11018/how-to-choose-directory-name-during-untarring
