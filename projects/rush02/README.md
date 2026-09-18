# C Piscine Rush 02

English | [한국어](README.ko.md)

A C program that converts a non-negative integer into words using a number
dictionary. Includes dictionary parsing, validation, and number grouping.

## Build and run

From this directory:

```sh
cd ex00
make
./rush-02 42
./rush-02 numbers.dict 123
```

The first form uses `numbers.dict` in the current working directory. The
second form accepts a dictionary path explicitly. The supplied dictionary
contains English number names; `42` produces `forty two`.

Use `make clean` to remove object files or `make fclean` to remove objects
and the executable.

Original source and contributor headers are preserved. The source repository
and commit are recorded in [sources.json](../../sources.json).
