# C Piscine Rush 01

A C solver for a grid puzzle with row and column uniqueness constraints and
edge clues describing how many buildings are visible. The solver searches
candidate heights recursively and checks the visibility constraints.

## Build and run

From this directory:

```sh
cc -Wall -Wextra -Werror ex00/*.c -o rush-01
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Pass the space-separated clues as one quoted argument. The clue groups are
top, bottom, left, and right. The example is a 4-by-4 puzzle.

## Contents

- `ex00/`: submitted program and its solver.
- `solution_mk2.c`, `solution_mk3.c`: alternative solver versions retained
  from the original repository; these are not included in the build above.

Original source and contributor headers are preserved. The source repository
and commit are recorded in [sources.json](../../sources.json).
