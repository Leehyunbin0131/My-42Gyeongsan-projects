# BSQ

English | [한국어](README.ko.md)

C Piscine project that finds and fills the largest obstacle-free square in a
map using dynamic programming. Supports map files and standard input.

## Build and run

From this directory:

```sh
make
./bsq map.txt
./bsq first-map.txt second-map.txt
./bsq < map.txt
```

The map header contains the number of rows followed by three distinct
characters: empty space, obstacle, and fill. For example:

```text
4.ox
....
....
....
....
```

This example produces four rows of `xxxx`. Use `make clean` to remove object
files or `make fclean` to remove objects and the executable.

## Source

- `src/`: input parsing, map handling, dynamic programming, and output.
- `include/`: project headers.

Original source and contributor headers are preserved. The source repository
and commit are recorded in [sources.json](../../sources.json).
