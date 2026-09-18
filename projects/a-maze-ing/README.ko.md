[English](README.md) | 한국어

*이 프로젝트는 jungblee, hyunlee가 42 교육과정의 일부로 제작했습니다.*

# A-Maze-ing

## 설명

설정 파일을 읽어 미로를 생성하고, 벽 정보와 최단 경로를 저장한 뒤 MiniLibX 창에 표시하는 Python 프로그램입니다.
`mazegen` 패키지는 그래픽이나 파일 처리 없이 독립적으로 사용할 수도 있습니다.

- `PERFECT=False`: 기본 모드입니다. 순환 경로를 추가하고 막다른 길을 줄입니다.
- `PERFECT=True`: 순환 경로 없이, 이동 가능한 임의의 두 칸 사이에 정확히 하나의 경로가 있는 미로를 생성합니다.

## 사용 방법

### 설치 및 실행

Ubuntu x86-64, Python 3.10 이상, `make`, [uv][uv-install]가 필요합니다.
창을 표시하려면 X11 디스플레이와 정상 동작하는 Vulkan 드라이버가 필요합니다.
Wayland 데스크톱에서는 XWayland를 사용합니다. 필요한 시스템 라이브러리는 XCB, XCB keysyms, Vulkan, zlib, libbsd입니다.

이 프로젝트의 루트 폴더에서 실행합니다:

~~~sh
make install
make run
~~~

`make install`은 `uv.lock`을 사용해 `.venv`와 Python 의존성을 준비합니다.
MLX는 함께 제공된 Ubuntu wheel에서 설치합니다. 시스템 라이브러리와 그래픽 드라이버는 별도로 설치해야 합니다.

프로그램을 직접 실행하거나 다른 설정 파일을 사용하려면 다음과 같이 실행합니다:

~~~sh
source .venv/bin/activate
python3 a_maze_ing.py config.txt
~~~

`config.txt`를 사용할 파일 경로로 바꿉니다. 이것이 유일한 명령줄 인자입니다.
프로그램은 미로를 `OUTPUT_FILE`에 저장한 뒤 창을 엽니다. 기존 출력 파일이 있으면 덮어씁니다.

### 조작 및 개발 명령어

| 키 | 동작 |
| --- | --- |
| `R` | 새 미로를 생성하고 저장한 뒤 표시 |
| `P` | 최단 경로 표시 전환 |
| `C` | 벽 색상 변경 |
| `Escape` / 닫기 버튼 | 종료 |

입구는 청록색, 출구는 산호색, 경로는 호박색, `42` 패턴은 보라색입니다.
칸 간격은 16픽셀로 고정되어 있어 큰 미로는 화면 밖으로 벗어날 수 있습니다.

| 명령어 | 동작 |
| --- | --- |
| `make debug` | Python의 `pdb` 디버거로 실행 |
| `make lint` | 과제에서 요구하는 옵션으로 flake8과 mypy 실행 |
| `make lint-strict` | 엄격 모드로 flake8과 mypy 실행 |
| `make package` | 프로젝트 루트에서 소스로 제출용 wheel 다시 빌드 |
| `make clean` | Python/mypy 캐시와 중간 빌드 파일 삭제 |

`make clean`은 가상 환경, 출력 미로, 제출용 wheel을 유지합니다.

## 설정

제공된 [config.txt](config.txt)의 내용입니다:

~~~ini
WIDTH=25
HEIGHT=17
ENTRY=0,0
EXIT=24,16
OUTPUT_FILE=maze.txt
PERFECT=False
SEED=42
~~~

| 키 | 필수 여부 | 값 |
| --- | --- | --- |
| `WIDTH`, `HEIGHT` | 필수 | 양의 정수: 열 개수와 행 개수 |
| `ENTRY`, `EXIT` | 필수 | 서로 다른 입구·출구 좌표, `x,y` |
| `OUTPUT_FILE` | 필수 | 출력 파일 경로 |
| `PERFECT` | 필수 | 정확히 `True` 또는 `False` |
| `SEED` | 선택 | 재현 가능한 생성을 위한 정수 |

좌표는 왼쪽 위 `(0, 0)`에서 시작합니다. x는 오른쪽으로, y는 아래쪽으로 증가합니다.
입구와 출구는 미로 안에 있어야 하며, 막힌 `42` 칸과 겹치면 안 됩니다.
기본 모드에서는 독립적인 순환 경로 두 개를 만들 수 없는 `(WIDTH - 1) * (HEIGHT - 1) < 2` 크기를 거부합니다.
미로가 패턴을 넣기에 너무 작으면 `42` 없이 생성하고 오류 메시지를 출력합니다.

한 줄에 `KEY=VALUE` 하나씩 작성합니다. 빈 줄과 `#`으로 시작하는 줄은 무시합니다.
앞뒤 공백은 허용하지만 키 이름의 대소문자는 구분합니다.
알 수 없는 키는 거부하며, 중복 키는 마지막 값을 사용합니다.
줄 끝 주석은 지원하지 않습니다. 상대 경로는 프로그램을 실행한 폴더를 기준으로 해석합니다.

`SEED`가 없으면 실행할 때마다 새 난수열을 시작합니다.
시드가 있으면 같은 설정·코드·Python 환경에서 같은 생성 순서를 재현합니다.
`R`은 난수열을 초기화하지 않고 이어서 사용합니다. 시드가 비어 있거나 정수가 아니면 오류입니다.

## 생성 알고리즘

**무작위 깊이 우선 탐색(DFS)**으로 방문하지 않은 이웃 칸을 연결합니다.
더 이동할 곳이 없으면 되돌아가 다른 이웃을 탐색합니다.
명시적인 스택을 사용해 Python의 재귀 깊이 제한을 피합니다.

그 결과 이동 가능한 모든 칸을 연결하는 트리가 만들어집니다. 완전 미로 모드는 여기서 멈춥니다.
기본 모드는 막다른 길의 벽을 추가로 열고, 독립적인 순환 경로를 최소 두 개 확보합니다.
이후 **너비 우선 탐색(BFS)**으로 입구에서 출구까지의 최단 경로를 찾습니다.

전체 간선 목록이나 별도의 서로소 집합 자료구조 없이 격자와 스택만 있으면 되므로 DFS를 선택했습니다.
생성과 경로 탐색의 시간·메모리 사용량은 칸 개수에 비례합니다.
`mazegen/`은 미로 생성을, `a_maze_ing.py`는 설정·파일·화면 출력을 담당합니다.

## 출력 형식

각 칸은 16진수 한 자리로 저장됩니다. 벽의 비트 값은 북쪽 `1`, 동쪽 `2`, 남쪽 `4`, 서쪽 `8`입니다.
**비트가 1이면 벽이 있고, 0이면 통로입니다.** 예를 들어 `A`는 동쪽과 서쪽 벽이 닫혀 있음을 뜻합니다.

파일에는 미로의 각 행이 한 줄씩 들어가고, 빈 줄 다음에 입구·출구·최단 경로가 각각 한 줄씩 들어갑니다.
경로에는 `N`, `E`, `S`, `W`를 사용합니다. 모든 줄은 개행 문자로 끝납니다.
두 칸짜리 완전 미로의 예시는 다음과 같습니다:

~~~text
D7

0,0
1,0
E
~~~

## 생성기 재사용

프로젝트 루트의 `mazegen-1.0.0-py3-none-any.whl`에는 생성기와 문서가 들어 있습니다.
MLX나 이미지 파일은 필요하지 않습니다. 다른 프로젝트의 가상 환경에서 wheel을 현재 폴더에 복사한 뒤 설치합니다:

~~~sh
python3 -m pip install ./mazegen-1.0.0-py3-none-any.whl
~~~

~~~python
from random import Random

from mazegen import MazeGenerator

rng = Random(42)
maze = MazeGenerator(25, 17, (0, 0), (24, 16), rng=rng, perfect=False)

print(maze.walls[0][0])
print(maze.entry, maze.exit)
print(maze.path)
~~~

처음 네 인자는 너비, 높이, 입구 좌표, 출구 좌표입니다.
`rng`는 필수이며, `perfect`의 기본값은 `False`입니다.
다음 생성에 같은 `rng`를 전달하면 난수열을 이어서 사용합니다.

`walls[y][x]`는 앞에서 설명한 벽 코드입니다.
`path`는 양 끝점을 포함한 `(x, y)` 좌표의 튜플입니다.
전체 API는 [패키지 안내](mazegen/README.ko.md)를 참고하세요.

## 팀 구성 및 프로젝트 관리

- `hyunlee`: 미로 생성, 최단 경로 탐색, 생성기 API.
- `jungblee`: 설정 처리, 파일 출력, MLX 화면 표시, 패키징.

처음에는 벽·경로 형식을 합의하고 생성기와 앱을 각각 구현한 뒤 통합하기로 계획했습니다.
알고리즘과 화면 구성을 비교한 후, 생성기 패키지 하나와 애플리케이션 파일 하나로 제출 구조를 단순화했습니다.

벽 코드와 좌표로 구성된 작은 인터페이스 덕분에 생성과 렌더링을 따로 테스트할 수 있었습니다.
개선할 점은 요구사항을 더 일찍 명확히 하는 것입니다. 시드 동작과 작은 미로에서의 `42` 배치 규칙은 나중에 다시 검토해야 했습니다.

버전 관리에는 Jujutsu/Git, 환경 관리에는 uv, 패키징에는 setuptools를 사용합니다.
검사에는 flake8, mypy, 별도 테스트, 제공된 미로 분석기를 사용합니다.

## 참고 자료

- [A-Maze-ing v2.3 과제 명세][subject]와 함께 제공된 `maze_analyzer.py`.
- [MIT DFS 강의][dfs]와 [MIT BFS 강의][bfs]: 그래프 탐색.
- [Python random][random]: 시드와 난수 생성기.
- [MiniLibX 문서 위치 및 Python API 안내](third_party/mlx/README.ko.md).
- [uv 프로젝트 안내][uv-project]와 [Python 패키징 안내][packaging].

AI는 요구사항 해석, 알고리즘 비교, `mazegen`과 `a_maze_ing.py`의 초안 작성 및 리팩터링,
테스트 작성, 패키징 점검, 문서 작성에 활용했습니다.

## 라이선스

프로젝트 코드에는 [Blue Oak Model License 1.0.0](LICENSE.md)([한국어 번역](LICENSE.ko.md))이 적용됩니다.
함께 제공된 MiniLibX는 [별도 MIT 라이선스](third_party/mlx/LICENSE.md)([한국어 번역](third_party/mlx/LICENSE.ko.md))를 유지합니다.

[subject]: https://cdn.intra.42.fr/pdf/pdf/224851/en.subject.pdf
[uv-install]: https://docs.astral.sh/uv/getting-started/installation/
[uv-project]: https://docs.astral.sh/uv/guides/projects/
[packaging]: https://packaging.python.org/en/latest/tutorials/packaging-projects/
[random]: https://docs.python.org/3/library/random.html
[dfs]: https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/resources/lecture-14-depth-first-search-dfs-topological-sort/
[bfs]: https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/resources/lecture-13-breadth-first-search-bfs/
