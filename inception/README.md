# Inception

### The project
We create a virtual machine running multiple services using Docker-compose. The services (Nginx, Wordpress, MariaDB - LEMP stack) run with their own Docker images and different volumes.

## How to start:

### Make the program:

### BUILD the Docker images with Docker-compose:
Build the images (use 'sudo' at the begining if you're on a Linux distribution and use '--no-cache' if needed)
  `make`

On the 42 Virtual Machines, stop the nginx service already in use:
  `(sudo) service nginx stop`

### MANAGE the services:
Check the state of the services:
  `make ps`

  Start the services:
  `make start`

  Stop the services:
  `make stop`

  Delete the former images:
  `make rm`

  Display the logs of all containers in the network:
  `make logs`

  Down the containers:
	`make down`
  
  Down the containers + clean the volumes:
	`make down -v`
  
  Stop the containers:
	`make stop`

  Stop & restart the containers:
	`make restart`


### CLEAN containers and images:
  Clean containers + images + volumes + network:
  `make clean`

  Clean containers + images + volumes + network + history:
  `make fclean`


## List of resources:

* Use Docker-compose for building a Wordpress service: https://docs.docker.com/samples/wordpress/
* good practices for building containers: https://cloud.google.com/architecture/best-practices-for-building-containers?hl=fr
* Daemon Nginx off: https://stackoverflow.com/questions/18861300/how-to-run-nginx-within-a-docker-container-without-halting
* Config Mariadb + use of bind address / Mariadb daemon + SQL config: https://www.val-r.fr/geek/os/linux/installer-un-serveur-linux-sous-debian/installation-et-configuration-du-serveur-mysql-mariadb/
* WordPress Deployment with NGINX, PHP-FPM and MariaDB using Docker Compose : https://medium.com/swlh/wordpress-deployment-with-nginx-php-fpm-and-mariadb-using-docker-compose-55f59e5c1a
* Install Wordpress-CLI for setting up wordpress without using the user interface: https://www.datanovia.com/en/fr/lessons/utilisation-de-docker-wordpress-cli-pour-gerer-les-sites-web-wordpress/
* Configure Wordpress from the CLI: https://blog.sucuri.net/2015/08/wp-cli-guide-installing-wordpress.html
* Run PHP in nodaemonize && allow as root: https://stackoverflow.com/questions/37313780/how-can-i-start-php-fpm-in-a-docker-container-by-default
* Config core install options with wordpress cli: https://developer.wordpress.org/cli/commands/core/install/  


### commands for navigating:

* checking health from Dockerfile (for MariaDB's service), add in mariadb:
    `healthcheck:
      test: ["CMD", "mysqladmin" ,"ping", "-h", "localhost"]
      timeout: 20s
      retries: 10`

* Testing container individually:
`docker build -t inception/mariadb .`
`docker run -it -p443:443 --env=MYSQL_DATABASE=wordpress_db --env=MYSQL_ADMIN=root --env=MYSQL_ADMIN_PWD=root_pwd --env=MYSQL_USER=user_wp --env=MYSQL_USER_PWD=pwd_wp inception/mariadb`
`docker run -it -p443:443 inception/nginx`

* Testing Mariadb for check on the databases:
`docker exec -ti mariadb bash`
`mysql` OR `mysql -p wordpress`
`SHOW DATABASES;`
`USE wordpress;`
`SHOW TABLES;`
`SELECT * FROM TABLE_NAME;`

* Showing users in SQL:
`SELECT user FROM mysql.user;`

* Giving rights to the $USER for the shared folder:
`sudo adduser $USER vboxsf; newgrp vboxsf`

* Access via commandline to port 80 (to check it's not accessible):
`curl http://127.0.0.1/`

* If WP theme not installed:
	`wp theme install twentytwentytwo --activate --allow-root`


### Explanations of Docker, Docker-compose & VMs:
Avant docker, on utilisait les machines virtuelles (VM) de façon redondante pour isoler les software/App/DB, ce qui consommait beaucoup de ressources et d’énergie côté serveur.

Ainsi pour chaque application déployée, une VM était “créée”, et chaque VM “simulait” un système d’exploitation (OS), ce qui consommait beaucoup de resources inutiles. Et docker est arrivé …

A la place de crée une VM par application, docker crée un conteneur par application. Les conteneurs docker communiquent directement avec l’API de l’OS du Server tout en isolant l’application.

L’utilisation des ressources est donc optimisée et scalable. De plus chaque conteneur peu être “orchestré” indépendamment grâce à un hyperviseur, de la même manière que les machines virtuelles.

Chaque conteneur est construit à partir d’une Image.

Une image c’est l’ensemble des fichiers, processus, librairies … nécessaire à la création d’un conteneur. Admettons que l’on veuille créer un conteneur Apache (Apache est un serveur web). Pour cela on va devoir récupérer dans un premier temps l’image Apache. Puis construire le conteneur à l’aide de cette image.

Les images sont organisées par dépendance, de la même manière que les packets sous linux. Une image Apache peu par exemple dépendre d’une image debian pour fonctionner.

Ainsi pour créer notre image, nous devons partir d’une image source puis la configurer en fonction de nos besoins en ligne de commande.

Le docker compose c’est comme l’orchestrateur qui va imprimer le nombre d’exemplaires que l’on veut avec les images que l’on veut (et même construire nos images en appelant nos dockerfile !) et ordonner les exemplaires fraichement imprimés de la manière que l’on aura défini. Le docker compose permet d’automatiser toute la construction d’une Architecture.

https://medium.com/@remyc/comprendre-docker-dockerfile-et-docker-compose-f21fe4ba22cb 

--------------------------------------------------------------------------------

Docker permet d'embarquer une application dans un ou plusieurs containers logiciels qui pourra s'exécuter sur n'importe quel serveur machine, qu'il soit physique ou virtuel. Docker fonctionne sous Linux comme Windows Server. C'est une technologie qui a pour but de faciliter les déploiements d'application, et la gestion du dimensionnement de l'infrastructure sous-jacente. 

Quelle différence avec la virtualisation ? La virtualisation permet, via un hyperviseur, de simuler une ou plusieurs machines physiques, et les exécuter sous forme de machines virtuelles (VM) sur un serveur ou un terminal. Ces VM intègrent elles-mêmes un OS sur lequel des applications sont exécutées. Ce n'est pas le cas du container logiciel. Le container fait en effet directement appel à l'OS de sa machine hôte pour réaliser ses appels système et exécuter ses applications, d'où son extrême légèreté. 

Comme le container n'embarque pas d'OS à la différence de la machine virtuelle, il est plus léger que cette dernière. Il n'a pas besoin d'activer un second système d'exploitation pour exécuter ses applications. Cela se traduit par un lancement beaucoup plus rapide. Pour parvenir au même résultat, les environnements de virtualisation ont besoin d'un pool de VM inactives provisionnées à l'avance.

Il devient possible d'imaginer réaliser du mirroring d'application et de l'équilibrage de charge entre clouds, et pourquoi pas des plans de reprise ou continuité d'activité entre clouds... voire même décider de la reprise d'un projet sur un cloud tiers.

Du fait de la disparition de l'OS intermédiaire des VM, les développeurs bénéficient aussi sur leur station de travail d'une pile applicative plus proche de celle de l'environnement de production, ce qui engendre mécaniquement moins de mauvaises surprises lors des déploiements.

Que fait Docker-compose ?
Docker Compose est un outil développé par Docker pour créer les architectures logicielles containérisées. Dans cette logique, chaque brique de l'application (code, base de données, serveur web...) sera hébergée par un container. Cet outil repose sur le langage YAML (pour Yet Another Markup Language) pour décrire l'architecture. Une fois celle-ci codée dans un fichier YAML, l'ensemble des services applicatifs seront générés via une commande unique.

https://www.journaldunet.fr/web-tech/guide-de-l-entreprise-digitale/1146290-docker-definition-docker-compose-docker-hub-docker-swarm-160919/

----------------------------------------------------------------------------------

Docker daemon is a persistent background process that manages the containers on a single host. It is a self-sufficient runtime that manages Docker objects such as images, containers, network, and storage. Docker daemon listens for REST API requests and performs a series of container operations accordingly.
A Docker daemon can also communicate with other Docker daemons if multiple hosts are managed as a service or a cluster.

https://unit42.paloaltonetworks.com/attackers-tactics-and-techniques-in-unsecured-docker-daemons-revealed/#:~:text=Docker%20daemon%20is%20a%20persistent,series%20of%20container%20operations%20accordingly.

-----------------------------------------------------------------------------------

One of the reasons Docker containers and services are so powerful is that you can connect them together, or connect them to non-Docker workloads. Docker containers and services do not even need to be aware that they are deployed on Docker, or whether their peers are also Docker workloads or not. Whether your Docker hosts run Linux, Windows, or a mix of the two, you can use Docker to manage them in a platform-agnostic way.

bridge: The default network driver. If you don’t specify a driver, this is the type of network you are creating. Bridge networks are usually used when your applications run in standalone containers that need to communicate. 
https://docs.docker.com/network/ 