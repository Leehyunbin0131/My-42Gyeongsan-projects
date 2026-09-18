[English](README.md) | 한국어

# C Piscine Rush 00

C로 사각형을 출력하는 연습 과제입니다. `rush00.c`부터 `rush04.c`까지
다섯 가지 테두리 모양과 공통 문자 출력 함수를 포함합니다.

## 빌드 및 실행

이 과제 폴더에서 제공된 실행 예제와 테두리 구현 하나를 함께 컴파일합니다:

```sh
cc -Wall -Wextra -Werror ex00/main.c ex00/ft_putchar.c ex00/rush00.c -o rush-00
./rush-00
```

다른 테두리를 사용하려면 `rush00.c`를 해당 파일로 바꿉니다. 각 파일이 같은 `rush` 함수를 정의하므로
한 번에 하나만 컴파일해야 합니다. 제공된 `main.c`는 정해진 테스트 사례들을 호출하며,
명령줄에서 가로·세로 크기를 입력받지는 않습니다.

원본 소스와 기여자 정보가 담긴 헤더를 유지했습니다. 원본 저장소와 커밋은
[sources.json](../../sources.json)에 기록되어 있습니다.
