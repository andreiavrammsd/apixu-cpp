all: build

env:
	sudo apt install -y gcc make build-essential valgrind

dep:
	sudo apt install -y libcurl4-openssl-dev

build:
	docker build -f dev/Dockerfile-build -t apixubuild .
	docker run --rm -ti -v $(PWD):/src -w /src apixubuild

api-up:
	docker build -f dev/Dockerfile-api -t apixuapi dev
	docker run -tid --rm -p 5000:5000 --name=apixuapi apixuapi

api-down:
	docker stop apixuapi
