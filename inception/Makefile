NAME	= inception

FILE	= srcs/docker-compose.yml

DOCKER_COMPOSE	= docker-compose -f $(FILE)

RM = sudo rm -rf

all: confighosts createdir ${NAME}

$(NAME):
		$(DOCKER_COMPOSE) build

confighosts:
		@sudo sed -i 's/127.0.0.1	localhost/127.0.0.1	localhost erecuero.42.fr/g' /etc/hosts

createdir:
		@sudo mkdir -p /home/erecuero/data/wordpress_volume
		@sudo mkdir -p /home/erecuero/data/mariadb_volume

build:
		$(DOCKER_COMPOSE) build
up:
		$(DOCKER_COMPOSE) up -d
start:
		$(DOCKER_COMPOSE) start
down:
		$(DOCKER_COMPOSE) down
destroy:
		$(DOCKER_COMPOSE) down -v
stop:
		$(DOCKER_COMPOSE) stop
restart:
		$(DOCKER_COMPOSE) stop
		$(DOCKER_COMPOSE) up -d
logs:
		$(DOCKER_COMPOSE) logs --tail=300

ps:
		$(DOCKER_COMPOSE) ps

clean: destroy
		${RM} /home/erecuero/data

fclean: clean
		docker system prune --all --volumes

re: fclean all

.PHONY: all clean fclean re

