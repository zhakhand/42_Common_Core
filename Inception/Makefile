all:
	docker compose -f srcs/docker-compose.yml up -d --build

down:
	docker compose -f srcs/docker-compose.yml down -v

clean: down
	docker system prune -af
	docker volume prune -f

fclean: clean
	sudo rm -rf ${HOME}/data/wordpress/*
	sudo rm -rf ${HOME}/data/mariadb/*

re: fclean all

.PHONY: all down clean fclean re