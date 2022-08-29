# 2021_1st-Semester_cpp_SnakeProject_J3
This is the C++ project that contains snakegame by Cmake.

## ***How to use (Ubuntu)***
step 1. install ncurses
```
$ sudo apt-get install libncurses5-dev libncursesw5-dev
```

step 2. install CMake
```
$ wget https://github.com/Kitware/CMake/releases/download/v3.20.0/cmake-3.20.0-linux-x86_64.tar.gz
$ tar xvf cmake-3.20.0-linux-x86_64.tar.gz
$ sudo rsync -K -a . /usr/local
$ cmake --version
```

step 3. compile(if required)
```
$ g++ -o source_name -lncurses
```

step 4. run
```
$ ./main.cpp
```
