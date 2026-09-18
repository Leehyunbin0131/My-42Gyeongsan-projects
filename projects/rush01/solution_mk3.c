/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_mk3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:00:00 by chwang            #+#    #+#             */
/*   Updated: 2026/02/01 16:15:00 by chwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		*make_1d_array(int size);
int		**make_2d_array(int rows, int cols);
int		**make_sequence(int **map, int size);
void	sort_by_second_desc(int **arr, int n);
int		count_visible_from_left(int **map, int row, int size);
int		count_visible_from_right(int **map, int row, int size);
int		count_visible_from_up(int **map, int col, int size);
int		count_visible_from_down(int **map, int col, int size);

static int		**map;
static int		size;

void	first_filter(int **row_used, int **col_used)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if (map[i][0] == 1 && map[i][1] != size)
		{
			map[i][1] = size;
			row_used[i][size] = 1;
			col_used[1][size] = 1;
		}
		if (map[i][size + 1] == 1 && map[i][size] != size)
		{
			map[i][size] = size;
			row_used[i][size] = 1;
			col_used[size][size] = 1;
		}
		i++;
	}
}

void	second_filter(int **row_used, int **col_used)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if (map[0][i] == 1 && map[1][i] != size)
		{
			map[1][i] = size;
			row_used[1][size] = 1;
			col_used[i][size] = 1;
		}
		if (map[size + 1][i] == 1 && map[size][i] != size)
		{
			map[size][i] = size;
			row_used[size][size] = 1;
			col_used[i][size] = 1;
		}
		i++;
	}
}

int		fill_row_cells(int row, int col_i, int **seq, int seq_i, int **row_used, int **col_used);
int		fill_the_row(int **seq, int seq_i, int **row_used, int **col_used);

static int	check_row_visible(int row)
{
	if (count_visible_from_left(map, row, size) != map[row][0])
		return (0);
	if (count_visible_from_right(map, row, size) != map[row][size + 1])
		return (0);
	return (1);
}

static int	check_col_visible(int col)
{
	if (count_visible_from_up(map, col, size) != map[0][col])
		return (0);
	if (count_visible_from_down(map, col, size) != map[size + 1][col])
		return (0);
	return (1);
}

int		fill_row_cells(int row, int col_i, int **seq, int seq_i, int **row_used, int **col_used)
{
	int	v;

	if (col_i > size)
	{
		if (!check_row_visible(row))
			return (0);
		return (fill_the_row(seq, seq_i + 1, row_used, col_used));
	}
	if (map[row][col_i] != 0)
		return (fill_row_cells(row, col_i + 1, seq, seq_i, row_used, col_used));
	v = 1;
	while (v <= size)
	{
		if (row_used[row][v] == 0 && col_used[col_i][v] == 0)
		{
			map[row][col_i] = v;
			row_used[row][v] = 1;
			col_used[col_i][v] = 1;
			if (fill_row_cells(row, col_i + 1, seq, seq_i, row_used, col_used))
				return (1);
			map[row][col_i] = 0;
			row_used[row][v] = 0;
			col_used[col_i][v] = 0;
		}
		v++;
	}
	return (0);
}

int		fill_the_row(int **seq, int seq_i, int **row_used, int **col_used)
{
	int	row;
	int	col;

	if (seq_i >= size)
	{
		col = 1;
		while (col <= size)
		{
			if (!check_col_visible(col))
				return (0);
			col++;
		}
		return (1);
	}
	row = seq[seq_i][0];
	return (fill_row_cells(row, 1, seq, seq_i, row_used, col_used));
}

void	third_filter(int **row_used, int **col_used)
{
	int	**seq;
	int	i;

	seq = make_sequence(map, size);
	sort_by_second_desc(seq, size);
	fill_the_row(seq, 0, row_used, col_used);
	i = 0;
	while (i < size)
	{
		free(seq[i]);
		i++;
	}
	free(seq);
}



int	**solution(int **map_in, int size_in)
{
	int	**row_used;
	int	**col_used;
	int	i;
	int	j;

	map = map_in;
	size = size_in;
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
	first_filter(row_used, col_used);
	second_filter(row_used, col_used);
	third_filter(row_used, col_used);
	return (map);
}