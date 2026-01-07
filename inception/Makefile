DATA_DIR = /home/$(USER)/data

all: volumes up

volumes:
	mkdir -p $(DATA_DIR)/mariadb
	mkdir -p $(DATA_DIR)/wordpress

up:
	docker compose up --build

down:
	docker compose down

clean:
	docker compose down -v
