/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:13:14 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/31 18:10:28 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_visible_from_left(int **map, int row, int size);
int	count_visible_from_right(int **map, int row, int size);
int	count_visible_from_up(int **map, int col, int size);
int	count_visible_from_down(int **map, int col, int size);
int	*make_1d_array(int size);
int	**make_2d_array(int rows, int cols);

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

int	solve(int **map, int row, int col, int size, int **row_used, int **col_used)
{
	int	height;
    int pos_hash;
	int	next_row;
	int	next_col;

	pos_hash = go_next(row, col, size);
	if (pos_hash == 1)
		return (1);
	next_row = pos_hash / 10;
	next_col = pos_hash % 10;
	height = 1;
	while (height <= size)
	{
		if (!row_used[row][height] && !col_used[col][height])
		{
			row_used[row][height] = 1;
			col_used[col][height] = 1;
			map[row][col] = height;
			if (check_view_hint(map, row, col, size))
			{
				if (solve(map, next_row, next_col, size, row_used, col_used))
					return (1);
			}
			row_used[row][height] = 0;
			col_used[col][height] = 0;
			map[row][col] = 0;
		}
		height++;
	}
	return (0);
}

int	**solution(int **map, int size)
{
	int	*next_pos;
	int	**row_used;
	int	**col_used;
	int	i;
	int	j;

	row_used = make_2d_array(size + 1, size + 1);
	col_used = make_2d_array(size + 1, size + 1);
	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			row_used[i][j] = 0;
			col_used[i][j] = 0;
			j++;
		}
		i++;
	}
	solve(map, 1, 1, size, row_used, col_used);
	return (map);
}
