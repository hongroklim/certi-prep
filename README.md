# Samsung SW Certi Preparation

2023년 삼성전자 DS부문 신입인턴 SW역량강화 교육 실습

## Configuration

Add file in `RUN_TESTS` in [CMakeLists.txt](./test/CMakeLists.txt).

## Build

```sh
$ mkdir build
$ cmake -S . -B build
$ cmake --build build
```

## Run

```sh
$ ./build/bin/run_test
```

## ccls (optional)

```sh
$ mkdir debug
$ cmake -H. -B debug -D CMAKE_BUILD_TYPE=Debug -D CMAKE_EXPORT_COMPILE_COMMANDS=YES
$ ln -s Debug/compile_commands.json .
```
