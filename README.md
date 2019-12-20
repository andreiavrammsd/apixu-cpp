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
- Time.cpp sscanf (Clang-Tidy: 'sscanf' used to convert a string to an integer value, but function will not report conversion errors; consider using 'strtol' instead)
- Parse time with tm struct?
- Classes or Structs for responses?
- http timeout
- build linux, win, mac
- clangd/clang tidy
- coding standards
- linter
- check fields names and types
- package management
- overload vs default arg
- multi language
- implement json serialize
- return const vector
- pack:
    - https://mavsdk.mavlink.io/develop/en/guide/toolchain.html#sdk_local_install
    - https://cmake.org/cmake/help/git-stage/cpack_gen/deb.html
    - https://gitlab.kitware.com/cmake/community/wikis/doc/cpack/Packaging-With-CPack
    - https://docs.ros.org/api/catkin/html/howto/format1/building_libraries.html

### Link
```
gcc -L/src/cmake-build-lib/ -Wl,-rpath=/src/cmake-build-lib/ -Wall -o testshared examples/conditions.cpp -lapixu -lstdc++ -lcurl
gcc -L/src/cmake-build-lib/ -Wl,-rpath=/src/cmake-build-lib/ -Wall -o teststatic examples/conditions.cpp cmake-build-lib/libapixu.a -lstdc++ -lcurl
```
