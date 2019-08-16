FROM ubuntu:18.04

RUN apt update && apt install -y g++ make valgrind libcurl4-openssl-dev wget && \
    wget https://github.com/Kitware/CMake/releases/download/v3.15.2/cmake-3.15.2-Linux-x86_64.tar.gz && \
    tar -xvf cmake-3.15.2-Linux-x86_64.tar.gz && \
    ln -s /cmake-3.15.2-Linux-x86_64/bin/cmake /usr/bin/cmake
