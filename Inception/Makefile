NAME = inception

all: up

up:
	@mkdir -p /home/dzhakhan/data/mariadb
	@mkdir -p /home/dzhakhan/data/wordpress
	docker-compose -f docker-compose.yml up -d --build

down:
	docker-compose -f docker-compose.yml down

stop:
	docker-compose -f docker-compose.yml stop

start:
	docker-compose -f docker-compose.yml start

logs:
	docker-compose -f docker-compose.yml logs -f

clean: down
	docker system prune -af

fclean: clean
	sudo rm -rf /home/dzhakhan/data/mariadb/*
	sudo rm -rf /home/dzhakhan/data/wordpress/*
	docker volume prune -f

re: fclean all

.PHONY: all up down stop start logs clean fclean re