# C Piscine Rush 00

Rectangle-printing exercises in C. The archive includes five border styles,
`rush00.c` through `rush04.c`, and a shared character-output function.

## Build and run

From this directory, compile one style with the supplied demonstration:

```sh
cc -Wall -Wextra -Werror ex00/main.c ex00/ft_putchar.c ex00/rush00.c -o rush-00
./rush-00
```

Replace `rush00.c` with another style to try it. Compile only one style at a
time, since each defines the same `rush` function. The supplied `main.c` calls
several fixed test cases; it does not read command-line dimensions.

Original source and contributor headers are preserved. The source repository
and commit are recorded in [sources.json](../../sources.json).
