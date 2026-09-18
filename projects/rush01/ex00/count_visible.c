/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_visible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:25:57 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/01 14:46:23 by ykang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_visible_from_left(int **map, int row, int size)
{
	int	col;
	int	max_height;
	int	visible_count;

	col = 1;
	max_height = 0;
	visible_count = 0;
	while (col <= size)
	{
		if (map[row][col] > max_height)
		{
			max_height = map[row][col];
			visible_count++;
		}
		col++;
	}
	return (visible_count);
}

int	count_visible_from_right(int **map, int row, int size)
{
	int	col;
	int	max_height;
	int	visible_count;

	col = size;
	max_height = 0;
	visible_count = 0;
	while (col >= 1)
	{
		if (map[row][col] > max_height)
		{
			max_height = map[row][col];
			visible_count++;
		}
		col--;
	}
	return (visible_count);
}

int	count_visible_from_up(int **map, int col, int size)
{
	int	row;
	int	max_height;
	int	visible_count;

	row = 1;
	max_height = 0;
	visible_count = 0;
	while (row <= size)
	{
		if (map[row][col] > max_height)
		{
			max_height = map[row][col];
			visible_count++;
		}
		row++;
	}
	return (visible_count);
}

int	count_visible_from_down(int **map, int col, int size)
{
	int	row;
	int	max_height;
	int	visible_count;

	row = size;
	max_height = 0;
	visible_count = 0;
	while (row >= 1)
	{
		if (map[row][col] > max_height)
		{
			max_height = map[row][col];
			visible_count++;
		}
		row--;
	}
	return (visible_count);
}
