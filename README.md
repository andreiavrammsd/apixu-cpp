# Apixu C++

C++ library for [Apixu Weather API](https://www.apixu.com/api.aspx)

## Install

## Usage

## Development
* CMake

##### Dependencies
```
sudo apt install libcurl4-openssl-dev
https://github.com/nlohmann/json
```

#### Runtime dependencies
```
sudo apt update
sudo apt install libcurl3 -y
```

### TODO
- http timeout
- build linux, win, mac
- clangd/clang tidy
- coding standards
- linter
- tests
- check fields names and types
- package management
- overload vs default arg
- multi language
- implement json serialize
- return const vector
- std::unique_ptr


```
docker build -f dev/Dockerfile -t apixudev .
docker run --rm -ti -v $PWD:/src apixudev bash
```
