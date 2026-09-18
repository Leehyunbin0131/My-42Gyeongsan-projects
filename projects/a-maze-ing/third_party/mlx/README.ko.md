[English](README.md) | 한국어

# MiniLibX 2.2

과제와 함께 제공된 `mlx-2.2.tgz`의 Ubuntu x86-64 wheel을 수정 없이 포함했습니다.
파일 이름은 `py3-none-any`이지만, 내부의 `libmlx.so`는 Linux x86-64 바이너리입니다.

- 파일: `ubuntu/mlx-2.2-py3-none-any.whl`
- SHA-256: `7a1a44b50b6295f574522ba1a1e589632c6299d193dec57c951e8fdfb3337195`
- 원본 압축 파일 SHA-256: `17c7197e0a0bdc6aa2172c14c712f2d16832f19485ca6f7aa94ddeff46346783`
- 저작권: 2025 42 Born2code - Olivier CROUZET
- 라이선스: MIT. [LICENSE.md](LICENSE.md)([한국어 번역](LICENSE.ko.md))를 참고하세요.

`pyproject.toml`은 이 wheel의 로컬 경로를 사용해 애플리케이션용 패키지를 설치합니다.
독립형 `mazegen` 패키지는 여기에 의존하지 않습니다.
호스트에는 XCB, XCB keysyms, Vulkan, zlib, libbsd, 정상 동작하는 그래픽 드라이버, X11 디스플레이가 필요합니다.
Wayland 데스크톱에서는 XWayland가 필요합니다.

## API 찾기

wheel에는 Python 래퍼와 C API 문서가 포함되어 있습니다.
`make install` 후 프로젝트 루트에서 다음 명령을 실행합니다:

~~~sh
.venv/bin/python -c 'import inspect; from mlx import Mlx; print(inspect.getfile(Mlx))'
~~~

출력된 `mlx.py`가 있는 폴더부터 살펴보세요.
`.venv/lib/python3.x/site-packages/mlx/` 경로는 Python 버전에 따라 달라집니다.

| 파일 | 확인할 내용 |
| --- | --- |
| `mlx.py` | Python 메서드 인자, 반환값, 콜백 연결 |
| `docs/mlx.h` | C API 선언, 상수, 리소스, 이미지 형식 |
| `docs/mlx.3`, `docs/mlx_new_window.3` | 컨텍스트와 창 생성·해제 |
| `docs/mlx_new_image.3` | PNG 로딩, 픽셀 메모리, 행 크기, 형식, 화면 출력 |
| `docs/mlx_loop.3` | 이벤트 루프, 훅, 루프 종료 |
| `docs/mlx_extra.3` | `mlx_sync` 및 동기화 명령 |
| `test/simple_test.py` | 창, 콜백, 이벤트 루프를 포함한 동작 예제 |

`.3` 파일은 C API 매뉴얼입니다. 편집기로 읽거나 해당 `docs` 폴더에서 `man -l mlx_new_image.3`을 실행합니다.
Python의 호출 규약은 `mlx.py`에서 확인하세요.
C에서 출력 포인터로 전달되는 값은 Python에서 튜플로 반환됩니다.
예를 들어 `mlx_get_data_addr(image)`는 `(memoryview, bits_per_pixel, size_line, pixel_format)`을 반환합니다.
마지막 값은 엔디언 플래그가 아니라 픽셀 형식입니다.

앱에서 `self.mlx`는 Python `Mlx` 래퍼이고, `self.mlx_ptr`은 `mlx_init()`이 반환한 네이티브 컨텍스트 핸들입니다.
`self.win_ptr`은 창 핸들, `self.frame_ptr`은 창 전체 크기의 이미지 핸들입니다.
`self.size_line`은 패딩을 포함한 이미지 한 행의 바이트 수입니다.
`Window`, `draw()`, `draw_tile()`은 MLX API가 아니라 이 프로젝트에 속합니다.

## 타입 선언

[typings/mlx/mlx.pyi](../../typings/mlx/mlx.pyi)는 앱이 사용하는 API만 기술합니다.
Pyright로 생성한 초안을 제공된 `mlx.py`와 `docs/mlx.h`에 대조해 검토하고 다듬었습니다.
실행 시 Python은 이 스텁이 아닌 원본 MLX 패키지를 사용합니다.

핸들을 반환하는 생성 함수는 실패 시 `None`을 반환합니다.
콜백 타입 변수 `_State`는 등록한 `param`의 타입과 콜백 매개변수의 타입을 연결합니다.
래퍼는 콜백 반환값을 무시합니다.
`mlx_hook` 선언은 앱에서 사용하는 닫기 이벤트 33만 다룹니다.
다른 API나 이벤트가 필요하면 스텁을 확장하세요.

basedpyright는 기본 `typings` 폴더를 사용합니다.
mypy는 `pyproject.toml`의 `mypy_path`를 통해 같은 스텁을 읽습니다.
이 스텁은 독립형 `mazegen` wheel에 포함되지 않습니다.
