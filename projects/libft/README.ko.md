[English](README.md) | 한국어

*이 프로젝트는 hyunlee가 42 교육과정의 일부로 제작했습니다.*

# Libft

## 결과

<p align="center">
  <img src="./assets/score-100.png" alt="Libft 100점" width="260">
</p>
<p align="center">
  <img src="./assets/tester-ok.png" alt="Libft 테스터 통과 결과" width="100%">
</p>

## 설명

Libft는 42 교육과정에서 제작한 C 라이브러리입니다. C 표준 라이브러리의 주요 기능을 다시 구현하고, 이후 42 과제에서 재사용할 수 있는 유틸리티 함수를 추가하는 것이 목표입니다.

빌드 결과물은 정적 라이브러리 `libft.a`입니다. 문자 판별, 메모리 조작, 문자열 처리, 메모리 할당 보조 함수, 파일 디스크립터 출력 함수, 연결 리스트 유틸리티를 포함합니다.

### 라이브러리 구성

문자 판별 및 변환:
`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`

메모리 함수:
`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

문자열 함수:
`ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`

변환 및 출력:
`ft_atoi`, `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

연결 리스트 유틸리티:
`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## 사용 방법

라이브러리 빌드:

```sh
make
```

오브젝트 파일 삭제:

```sh
make clean
```

오브젝트 파일과 정적 라이브러리 삭제:

```sh
make fclean
```

처음부터 다시 빌드:

```sh
make re
```

## 참고 자료

- 개인 Notion 학습 노트: https://coconut-munchkin-952.notion.site/42gs-79872d44d901462c8b583fa5b48e7f03

학습과 검증 과정에서 AI의 도움을 받았습니다. 먼저 구현할 각 함수에 대해 관련 매뉴얼의 요구 동작을 번역하고 설명하도록 요청했습니다. 이후 경계 조건을 포함한 작은 `main` 프로그램을 생성하도록 요청해, 직접 구현한 함수가 올바르게 동작하는지 테스트했습니다. 마지막으로 AI를 활용해 `libftTester`에 경계 조건을 추가하고 테스트 범위를 확장한 뒤, 개선한 테스터로 구현 코드를 검증했습니다: https://github.com/Leehyunbin0131/libftTester
