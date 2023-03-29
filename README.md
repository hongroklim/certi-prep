# Samsung SW Certi Preparation

2023년 상반기 삼성전자 DS부문 신입인턴 SW역량강화 교육 실습

## Configuration

Add file path in `RUN_TESTS` variable in [CMakeLists.txt](./test/CMakeLists.txt).

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

## Solutions

* [SW Expert Academy](https://swexpertacademy.com/main/main.do) (swea)
* [Jungol](http://www.jungol.co.kr) (jgol)

| Site | No.   | Title | Tags |
|:----:| -----:|:----- |:-----|
| swea | 1206  | [S/W 문제해결 기본] 1일차 - View |  |
| swea | 1215  | [S/W 문제해결 기본] 3일차 - 회문1 | `stack` |
| swea | 1240  | [S/W 문제해결 응용] 1일차 - 단순 2진 암호코드 | `atoi` |
| swea | 1219  | [S/W 문제해결 기본] 4일차 - 길찾기 | `dfs` |
| swea | 1221  | [S/W 문제해결 기본] 5일차 - GNS | `atoi` |
| jgol | 1733  | 오목 | `dfs` |
| jgol | 2194  | 요플레 공장 | `greedy` |
| jgol | 1295  | 이진탐색 | `bin_search` |
| jgol | 1374  | 긴 자리 덧셈 뺄셈 | `atoi` |
| swea | 1244  | [S/W 문제해결 응용] 2일차 - 최대 상금 | `dfs`, `atoi` |
| swea | 1265  | [S/W 문제해결 응용] 9일차 - 달란트2 | `memo` |
| swea | 1266  | [S/W 문제해결 응용] 9일차 - 소수 완제품 확률 | `memo`, `ncr` |
| swea | 1218  | [S/W 문제해결 기본] 4일차 - 괄호 짝짓기 | `stack` |
| swea | 1234  | [S/W 문제해결 기본] 10일차 - 비밀번호 | `stack` |
| jgol | 3572  | 후위표기법2(후위표현식I) | `stack` |
| swea | 1225  | [S/W 문제해결 기본] 7일차 - 암호생성기 |  |
| swea | 1245  | [S/W 문제해결 응용] 2일차 - 균형점 | `bin_search` |
| swea | 1256  | [S/W 문제해결 응용] 6일차 - K번째 접미어 | `suffix` |
| swea | 1257  | [S/W 문제해결 응용] 6일차 - K번째 문자열 | `suffix` |
| jgol | 1620  | 전화번호 속의 암호 | `string`, `atoi` |
| swea | 10804 | 문자열의 거울상 | `stack` |
| swea | 1211  | [S/W 문제해결 기본] 2일차 - Ladder2 | `dfs` |
| swea | 1227  | [S/W 문제해결 기본] 7일차 - 미로2 | `dfs` |
| jgol | 1695  | 단지번호붙이기 | `flood_fill` |
| jgol | 1078  | 저글링 방사능 오염 | `bfs` |
| swea | 1267  | [S/W 문제해결 응용] 10일차 - 작업순서  | `topology` |
| swea | 1249  | [S/W 문제해결 응용] 4일차 - 보급로 | `dijkstra` |
| jgol | 1462  | 보물섬 | `dfs` |
| jgol | 1060  | 최소비용신장트리 | `MST`, `prim` |
| swea | 1251  | [S/W 문제해결 응용] 4일차 - 하나로 | `prim` |
| swea | 1849  | 영준이의 무게측정 | `disjoint_set` |
| swea | 1231  | [S/W 문제해결 기본] 9일차 - 중위순회 | `tree` |
| swea | 1248  | [S/W 문제해결 응용] 3일차 - 공통조상 | `LCA` |
| jgol | 1726  | 구간의 최대값1 | `segment_tree` |
| jgol | 3142  | ID검사 | `hash` |
| jgol | 2613  | 토마토(고) | `bfs` |
| jgol | 2058  | 고돌이 고소미 | `bfs` |
| swea | 1247  | [S/W 문제해결 응용] 3일차 - 최적 경로 | `backtrack` |
| jgol | 1889  | N Queen | `backtrack` |
| jgol | 1662  | 비숍 | `backtrack` |
| jgol | 1824  | 스도쿠 | `backtrack` |
| jgol | 1077  | 배낭채우기1 | `dp` |
| jgol | 1078  | 배낭채우기2 | `dp` |
| jgol | 2112  | 세 줄로 타일 깔기(3열로 타일깔기) | `dp` |
| jgol | 2191  | 최소 편집 | `edit_dist` |
| swea | 1263  | [S/W 문제해결 응용] 8일차 - 사람 네트워크2 | `floyd` |
| swea | 1260  | [S/W 문제해결 응용] 7일차 - 화학물질2 | `dp` |
| jgol | 1825  | 기업투자 | `dp` |
| jgol | 1129  | 평면내 선분의 교점 | `ccw` |
| jgol | 1151  | 볼록다각형(convexhull) | `ccw`, `graham` |
| jgol | 1225  | 사람감시 | |
| jgol | 3336  | 직각다각형 | |
|      | 0101  | 개미탈출 | |
|      | 0102  | 최소 섬 | `dijkstra` |
|      | 0201  | 타일 채우기 | `DP` |
|      | 0202  | 말뚝울타리치기 | `graham` |
|      | 0301  | 최소증가스패닝트리 | `mst`, `djkstra` |
|      | 0302  | 길찾기 | `dfs` |
