# Apixu C++

C++ library for [Apixu Weather API](https://www.apixu.com/api.aspx)

Apixu is now [weatherstack](https://weatherstack.com/). This library is developed only for learning, not for any kind of usage, and is not associated with any company.

## Development

See [Makefile](Makefile) for tools and dependencies.

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
- implement json serialize
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

### Resources
- ! http://www.stroustrup.com/C++.html
- https://www.viva64.com/en/b/0658/
- https://stackoverflow.com/questions/4781852/how-to-convert-a-string-to-datetime-in-c
- https://github.com/oclint/oclint
- https://blog.jetbrains.com/clion/2019/10/clion-2019-3-eap-coverage-cmake-defaults-lldb/
- https://github.com/pyarmak/cmake-gtest-coverage-example/blob/master/cmake/modules/CodeCoverage.cmake
- https://medium.com/@naveen.maltesh/generating-code-coverage-report-using-gnu-gcov-lcov-ee54a4de3f11
- https://github.com/lefticus/cppbestpractices/blob/master/03-Style.md
- https://github.com/lefticus/cppbestpractices/blob/master/00-Table_of_Contents.md
- https://google.github.io/styleguide/cppguide.html#Ownership_and_Smart_Pointers
- https://www.jetbrains.com/help/clion/clangformat-as-alternative-formatter.html
- https://codereview.stackexchange.com/questions/176508/basic-cmake-c-project-structure
