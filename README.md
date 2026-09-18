# My 42 Gyeongsan Projects

My 42 Gyeongsan projects and study archives, including C programming,
Python exercises, algorithms, and maze generation.

All project source archives are available directly under [`projects/`](projects/).
Open a project directory for its source code, README, and available build files.

## Projects

| Project | Description | Source |
| --- | --- | --- |
| C Piscine | C Piscine exercises from 42 Gyeongsan | [Source & README](projects/c-piscine/) |
| Rush 00 | Rectangle printing with five border styles | [Source & README](projects/rush00/) |
| Rush 01 | Grid puzzle solver with visibility constraints | [Source & README](projects/rush01/) |
| Rush 02 | Dictionary-based number-to-words conversion | [Source & README](projects/rush02/) |
| BSQ | Largest obstacle-free square search using dynamic programming | [Source & README](projects/bsq/) |
| Libft | Custom C library for the 42 curriculum | [Source & README](projects/libft/) |
| get_next_line | Line-by-line file descriptor reader for the 42 curriculum | [Source & README](projects/get_next_line/) |
| ft_printf | Custom printf implementation for the 42 curriculum | [Source & README](projects/ft_printf/) |
| push_swap | Two-stack sorting with adaptive strategies and operation benchmarking | [Source & README](projects/push_swap/) |
| A-Maze-ing | Configurable maze generation, shortest-path solving, and MiniLibX visualization | [Source & README](projects/a-maze-ing/) |

## Python Modules

| Module | Topics | Archive |
| --- | --- | --- |
| Python 00 | Functions, input/output, loops, and recursion | [ex0–ex7](projects/python00/) |
| Python 01 | Classes, validation, inheritance, and garden analytics | [ex0–ex6](projects/python01/) |
| Python 02 | Exceptions, custom errors, and cleanup with finally | [ex0–ex4](projects/python02/) |

## Testing Tools

I also maintain a fork of `libftTester` for my Libft verification workflow:
[Leehyunbin0131/libftTester](https://github.com/Leehyunbin0131/libftTester).

This fork keeps the original Tripouille-style commands while adding broader
edge-case coverage, Ubuntu 24.04 / WSL-safe leak tracking, and Makefile checks
for common 42 Libft requirements.

Useful commands:

```sh
make m
make checkmakefile
make calloc
make dockerm
```

## Archive Notes

Projects are snapshots of the original GitHub and Vogsphere repositories.
Original source files, project documentation, and assets are preserved; Python
module READMEs provide an exercise inventory and runnable examples. BSQ and
Rush READMEs document their build and run commands. Compiled
C Piscine executables are omitted, with exclusions recorded in `sources.json`.

Earlier GitHub repositories remain available as historical archives. This
repository now provides direct access to all listed project sources.

[`sources.json`](sources.json) records each archive's source repository, exact
commit, and original file list. Vogsphere access requires an authorized SSH key.
The listed exercises describe the files present, not an evaluation score or
completion certification.

A-Maze-ing was created by **jungblee and hyunlee**. Its
[Blue Oak license](projects/a-maze-ing/LICENSE.md) and the bundled
[MiniLibX license](projects/a-maze-ing/third_party/mlx/LICENSE.md) are preserved
and apply to their respective files.
