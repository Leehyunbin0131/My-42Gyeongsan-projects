# 42 경산 프로젝트

42 경산에서 구현한 과제 결과물을 모았습니다.

각 프로젝트 링크에서 소스 코드와 구현 설명을 확인할 수 있습니다.

## 마일스톤 0

| 프로젝트 | 구현 내용 |
| --- | --- |
| [Libft](projects/libft/) | 문자열·메모리 처리 함수와 연결 리스트를 포함한 C 라이브러리 |

## 마일스톤 1

| 프로젝트 | 구현 내용 |
| --- | --- |
| [get_next_line](projects/get_next_line/) | 파일 디스크립터에서 한 줄씩 읽는 함수 |
| [ft_printf](projects/ft_printf/) | printf의 형식 지정과 출력 기능 구현 |
| [push_swap](projects/push_swap/) | 두 스택을 이용한 정렬과 연산 횟수 벤치마크 |

## 마일스톤 2

| 프로젝트 | 구현 내용 |
| --- | --- |
| [A-Maze-ing](projects/a-maze-ing/) | 미로 생성, 최단 경로 탐색, MiniLibX 시각화 |

### Python 과제

| 모듈 | 구현 내용 | 소스 코드 |
| --- | --- | --- |
| Python 00 | 정원 정보 입출력, 면적·수확량 계산, 씨앗 재고 출력 | [ex0–ex7](projects/python00/) |
| Python 01 | 식물 클래스, 성장 처리, 데이터 검증, 정원 통계 | [ex0–ex6](projects/python01/) |
| Python 02 | 오류 발생·처리, 사용자 정의 예외, finally 정리 예제 | [ex0–ex4](projects/python02/) |

## C Piscine

| 과제 | 구현 내용 |
| --- | --- |
| [C Piscine](projects/c-piscine/) | 문자열 처리, 수학 연산, 배열·메모리 할당 함수 구현 |
| [Rush 00](projects/rush00/) | 다섯 가지 테두리 모양으로 사각형 출력 |
| [Rush 01](projects/rush01/) | 방향별로 보이는 높이 개수 조건을 만족하는 격자 퍼즐 풀이 |
| [Rush 02](projects/rush02/) | 사전을 활용해 숫자를 단어로 변환 |
| [BSQ](projects/bsq/) | 동적 계획법으로 장애물이 없는 가장 큰 정사각형 탐색 |

## 테스트와 검증

Libft 검증을 위해 포크한
[Leehyunbin0131/libftTester](https://github.com/Leehyunbin0131/libftTester)를 별도로 관리합니다.

기존 Tripouille 방식의 명령어를 유지하면서 경계 조건 테스트를 확장하고,
Ubuntu 24.04 및 WSL 환경을 고려한 메모리 누수 추적과
42 Libft의 일반적인 요구사항에 맞춘 Makefile 검사를 추가했습니다.

## 라이선스

A-Maze-ing은 **jungblee와 hyunlee**가 공동 제작했으며,
[Blue Oak 라이선스](projects/a-maze-ing/LICENSE.md)를 따릅니다.
포함된 MiniLibX에는 [별도 MIT 라이선스](projects/a-maze-ing/third_party/mlx/LICENSE.md)가 적용됩니다.

## 기여자

- [Leehyunbin0131](https://github.com/Leehyunbin0131) — 프로젝트 작성 및 유지보수.
- OpenAI Codex — 저장소 통합 후 정리와 문서 작성·한국어 번역을 지원한 AI 도구.
