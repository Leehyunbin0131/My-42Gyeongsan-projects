# My 42 Gyeongsan Projects

My 42 Gyeongsan projects and study archives, including C programming,
Python exercises, algorithms, and maze generation.

Existing projects link to their dedicated repositories. New archives are
available directly under [`projects/`](projects/).

## Projects

| Project | Description | Repository |
| --- | --- | --- |
| C Piscine | C Piscine exercises from 42 Gyeongsan | [42Gyeongsan-C_Piscine](https://github.com/Leehyunbin0131/42Gyeongsan-C_Piscine) |
| Libft | Custom C library for the 42 curriculum | [42Gyeongsan-Libft](https://github.com/Leehyunbin0131/42Gyeongsan-Libft) |
| get_next_line | Line-by-line file descriptor reader for the 42 curriculum | [42Gyeongsan-get_next_line](https://github.com/Leehyunbin0131/42Gyeongsan-get_next_line) |
| ft_printf | Custom printf implementation for the 42 curriculum | [42Gyeongsan-ft_printf](https://github.com/Leehyunbin0131/42Gyeongsan-ft_printf) |
| push_swap | Two-stack sorting with adaptive strategies and operation benchmarking | [42Gyeongsan-push_swap](https://github.com/Leehyunbin0131/42Gyeongsan-push_swap) |
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

The Python modules and A-Maze-ing are snapshots of the supplied Vogsphere
repositories. Original source files are preserved; Python module READMEs
provide an exercise inventory and runnable examples.

[`sources.json`](sources.json) records each archive's source repository, exact
commit, and original file list. Vogsphere access requires an authorized SSH key.
The listed exercises describe the files present, not an evaluation score or
completion certification.

A-Maze-ing was created by **jungblee and hyunlee**. Its
[Blue Oak license](projects/a-maze-ing/LICENSE.md) and the bundled
[MiniLibX license](projects/a-maze-ing/third_party/mlx/LICENSE.md) are preserved
and apply to their respective files.
