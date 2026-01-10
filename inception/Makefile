DATA_DIR = /home/$(USER)/data
COMPOSE = docker compose -f srcs/docker-compose.yml --env-file srcs/.env

all: volumes up

volumes:
	@printf "Building the volumes...\n"
	@mkdir -p $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress

up:
	@printf "Configurating and initializing the server...\n"
	@$(COMPOSE) up --build

down:
	@printf "Stopping the server...\n"
	@$(COMPOSE) down

clean:
	@printf "Stopping the server and deleting Docker volumes...\n"
	@$(COMPOSE) down -v

fclean:
	@printf "Stopping the server and deleting Docker volumes and built images...\n"
	@$(COMPOSE) down -v --rmi all

delete:
	@printf "Deleting all data...\n"
	@sudo rm -rf $(DATA_DIR)

re: fclean all
