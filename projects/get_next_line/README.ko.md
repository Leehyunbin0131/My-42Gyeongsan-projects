[English](README.md) | 한국어

*이 프로젝트는 hyunlee가 42 교육과정의 일부로 제작했습니다.*

# get_next_line

## 결과

<p align="center">
  <img src="./assets/score-100.png" alt="get_next_line 100점" width="260">
</p>
<p align="center">
  <img src="./assets/tester-ok.png" alt="get_next_line 테스터 통과 결과" width="100%">
</p>

## 설명

get_next_line은 파일 디스크립터에서 한 번에 한 줄씩 읽는 함수를 구현하는 42 교육과정 프로젝트입니다. 정적 변수, 반복적인 `read` 호출, 연속된 함수 호출 사이의 힙 메모리 관리를 이해하는 것이 목표입니다.

이 함수는 다음 줄을 반환하며, 줄 끝에 개행 문자가 있으면 함께 반환합니다. 아직 반환하지 않은 데이터는 정적 백업 버퍼에 보관해 다음 호출에서 이어서 읽습니다.

### 구현 설명

입력은 `BUFFER_SIZE`로 정한 크기만큼 읽습니다. 개행 문자나 파일 끝에 도달할 때까지 읽은 데이터를 백업 버퍼에 덧붙입니다.

한 줄이 완성되면 해당 줄을 추출해 호출자에게 반환합니다. 개행 문자 뒤에 남은 바이트는 다음 호출을 위해 정적 백업 버퍼에 다시 저장합니다.

파일 끝에 도달하거나 읽기 오류가 발생하면 할당한 버퍼를 해제해, 반복 호출 시 불필요한 메모리가 남지 않도록 합니다.

## 사용 방법

원하는 `BUFFER_SIZE`를 지정해 컴파일합니다:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

헤더를 포함하고 유효한 파일 디스크립터로 `get_next_line`을 호출합니다:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

## 참고 자료 및 AI 활용

### 참고 자료

* [Linux 프로그래머 매뉴얼 (man 2 read)](https://man7.org/linux/man-pages/man2/read.2.html)
* [C 정적 변수 설명](https://en.wikipedia.org/wiki/Static_variable)
* 42 C Piscine 및 본과정 문서
* 개인 Notion 학습 노트: https://coconut-munchkin-952.notion.site/2026_42gs-79872d44d901462c8b583fa5b48e7f03

### AI 활용 명시

이 프로젝트를 개발하는 동안 AI 도우미(Gemini)는 **대화형 학습 도우미**로만 활용했습니다.

* **활용한 용도:** 메모리 할당 개념을 깊이 이해하고, 세그멘테이션 오류와 메모리 누수의 논리적 원인(예: `ft_substr` 처리 중 발생하는 댕글링 포인터)을 파악하며, Norminette 제약 조건에 맞게 코드를 모듈화하는 구조를 논의했습니다.
* **활용하지 않은 용도:** 최종 코드를 생성하거나, 학습 과정을 건너뛰거나, 실제 로직을 작성하는 데 AI를 사용하지 않았습니다. 모든 코드 구현, 디버깅, 최종 해결은 직접 수행했습니다.
