/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:13:14 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/01 19:34:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_error(int error_code);
int	count_visible_from_left(int **map, int row, int size);
int	count_visible_from_right(int **map, int row, int size);
int	count_visible_from_up(int **map, int col, int size);
int	count_visible_from_down(int **map, int col, int size);

int	check_view_hint(int **map, int row, int col, int size)
{
	if (col == size)
	{
		if (count_visible_from_left(map, row, size) != map[row][0])
			return (0);
		if (count_visible_from_right(map, row, size) != map[row][size + 1])
			return (0);
	}
	if (row == size)
	{
		if (count_visible_from_up(map, col, size) != map[0][col])
			return (0);
		if (count_visible_from_down(map, col, size) != map[size + 1][col])
			return (0);
	}
	return (1);
}

int	check_duplicate(int **map, int row, int col, int num)
{
	int	i;

	i = 1;
	while (i < col)
	{
		if (map[row][i] == num)
			return (0);
		i++;
	}
	i = 1;
	while (i < row)
	{
		if (map[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	go_next(int row, int col, int size)
{
	if (row > size)
		return (1);
	if (col == size)
	{
		return (((row + 1) * 10) + 1);
	}
	else
	{
		return ((row * 10) + (col + 1));
	}
	return (0);
}

int	solve(int **map, int row, int col, int size)
{
	int	height;
	int	next_pos[3];

	next_pos[2] = go_next(row, col, size);
	if (next_pos[2] == 1)
		return (1);
	next_pos[0] = next_pos[2] / 10;
	next_pos[1] = next_pos[2] % 10;
	height = 1;
	while (height <= size)
	{
		if (check_duplicate(map, row, col, height))
		{
			map[row][col] = height;
			if (check_view_hint(map, row, col, size))
			{
				if (solve(map, next_pos[0], next_pos[1], size) == 1)
					return (1);
			}
			map[row][col] = 0;
		}
		height++;
	}
	return (-99);
}

int	**solution(int **map, int size)
{
	int	is_error;

	is_error = solve(map, 1, 1, size);
	print_error(is_error);
	return (map);
}
