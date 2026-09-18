[English](README.md) | 한국어

*이 프로젝트는 hyunlee가 42 교육과정의 일부로 제작했습니다.*

# ft_printf

## 결과

<p align="center">
  <img src="./assets/score-100.png" alt="ft_printf 100점" width="260">
</p>
<p align="center">
  <img src="./assets/tester-ok.png" alt="ft_printf 테스터 통과 결과" width="100%">
</p>

## 설명

ft_printf는 42 교육과정에서 C 표준 라이브러리의 `printf` 함수를 직접 구현한 프로젝트입니다. 가변 인자를 이해하고 과제의 제약 조건에 맞게 서식 출력을 구현하는 것이 목표입니다.

라이브러리는 `libftprintf.a`로 빌드되며, 필수 변환인 `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`를 지원합니다.

### 구현 설명

서식 문자열을 한 번 순회하며 처리합니다. `%`를 만나면 다음 문자에 맞는 변환 함수를 호출하고, 출력한 바이트 수를 `ft_printf`에 반환합니다.

부호 없는 정수, 16진수, 포인터 값은 재귀적인 진법 변환으로 출력합니다. 별도 버퍼를 사용하지 않으면서 올바른 자릿수 순서를 유지합니다.

과제 테스터가 기대하는 glibc 동작에 맞춰 널 문자열은 `(null)`, 널 포인터는 `(nil)`로 출력합니다.

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

- Linux 매뉴얼: `man 3 printf`, `man 3 stdarg`
- 테스터: https://github.com/Leehyunbin0131/printfTester
- 개인 Notion 학습 노트: https://coconut-munchkin-952.notion.site/2026_42gs-79872d44d901462c8b583fa5b48e7f03

학습과 디버깅 과정에서 AI의 도움을 받았습니다. Google Gemini를 활용해 가변 인자를 살펴보고, Norminette 제약 조건에 맞는 프로젝트 구조를 논의하며, 디버깅 출력을 분석했습니다. 구현 코드를 생성하거나 복사해 붙여 넣는 용도로는 사용하지 않았습니다.
