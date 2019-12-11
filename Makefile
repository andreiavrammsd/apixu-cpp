all: build

env:
	sudo apt install -y gcc make build-essential valgrind

dep:
	sudo apt install -y libcurl4-openssl-dev

build:
	docker build -f dev/Dockerfile-build -t apixubuild .
	docker run --rm -ti -v $(PWD):/src -w /src apixubuild

proxyup: check-env
	docker build -f dev/Dockerfile-proxy -t apixuproxy dev
	docker run -tid --rm -p 5000:5000 -e HOST=$(HOST) --name=apixuproxy apixuproxy

proxydown:
	docker stop apixuproxy

check-env:
ifndef HOST
	$(error HOST is undefined)
endif
