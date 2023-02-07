all : docker_compose_up

build: create_containers_mounts
	@cd srcs && docker-compose up --build -d

docker_compose_up: create_containers_mounts
	@cd srcs && docker-compose --env-file .env up -d

create_containers_mounts:
	@sudo mkdir -pv ~/data/mariadb
	@sudo mkdir -pv ~/data/wordpress

delete_containers_mounts:
	@sudo rm -rf ~/data/mariadb
	@sudo rm -rf ~/data/wordpress


clean:
	@docker-compose -f ./srcs/docker-compose.yml --env-file ./srcs/.env down

fclean: clean delete_containers_mounts
	@docker system prune -a

re: fclean all