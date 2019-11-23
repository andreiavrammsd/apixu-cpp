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

### Link
```
gcc -L/src/cmake-build-lib/ -Wl,-rpath=/src/cmake-build-lib/ -Wall -o testshared examples/conditions.cpp -lapixu -lstdc++ -lcurl
gcc -L/src/cmake-build-lib/ -Wl,-rpath=/src/cmake-build-lib/ -Wall -o teststatic examples/conditions.cpp cmake-build-lib/libapixu.a -lstdc++ -lcurl
```
