**case0**: 트리 구조에서 총 연료비(`w`)를 계산하는 방법
```
lvl 0:    5
lvl 1: 3  1  7
lvl 2:         6
```
`0*(5) + 1*(3+1+7) + 2*(6) = 23`

**case1**: 루트노드 `w=5` -> `w=7` 변경
```
lvl 0:       7
lvl 1:   5       6
lvl 2: 3   1
```
`0*(7) + 1*(5+6) + 2*(1+3) = 19`

**case0 -> case1 비교**

```
          <case0>     <case1>
lvl 0  |   5       |        7  |
lvl 1  |  3 1   7  |   5    6  |
lvl 2  |        6  |  3 1      |
```

* `w=7` 기준 서브트리: lvl 1 감소 -(7+6) = `-(13)`
* `w=5` 기준 `w=7` 제외 서브트리: lvl 1 증가 +(22-13) = `+(09)`

**아이디어**: 변화량이 가장 작은 음수인 자식노드를 루트노드로 선택

**변화량 계산방법**: 각 노드 기준 서브트리의 연료비 합 (`par_w`) 활용

**case0의 `par_w`**

```
lvl 0:        5(22)
lvl 1: 3(03)  1(01)  7(13)
lvl 2:                     6(06)
```

**case1 이후 `par_w`**

```
lvl 0:                     7(22)
lvl 1:       5(09)                 6(06)
lvl 2: 3(03)       1(01)
```

**`par_w` 활용 case0 -> case1 계산**

* 감소량: `w=7` 기준 서브트리 -(13)
* 증가량: `w=5` 기준 `w=7` 제외 서브트리 +(22-13) = +(09)

* `-(13) +(09) = -4`
* `+(22) - 2*(13) = -4`
* 모든 노드 w합`par_w(5)=22`에서 선택한 서브트리 w합`par_w(7)=13`의 두 배를 뺀 값
* `par_w(root) - 2*par_w(child)`

**탐색 시작 노드**: 임의의 노드
**탐색 중단 조건**: 가장 작은 변화량이 음수가 아닐 때
**가장 작은 변화량이 2개 이상이라면?**: `par_w(root) > 2*par_w(c)` 이니 그 변화량은 양수가 되므로 자연스럽게 탐색 중단