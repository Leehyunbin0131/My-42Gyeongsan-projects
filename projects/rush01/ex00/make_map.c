/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:17:06 by chwang            #+#    #+#             */
/*   Updated: 2026/01/31 18:32:05 by chwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_number(char num);
int		**make_2d_array(int rows, int cols);
int		*make_1d_array(int count);

static int	*parse_values(char *values, int size)
{
	int	*result;
	int	count;
	int	i;
	int	val;

	result = make_1d_array(size);
	if (!result)
		return (NULL);
	count = 0;
	i = 0;
	while (count < size)
	{
		while (values[i] == ' ')
			i += 1;
		val = is_number(values[i]);
		result[count++] = val;
		i += 1;
	}
	return (result);
}

static void	fill_zeros(int **map, int length)
{
	int	r;
	int	c;
	int	size;

	size = length + 2;
	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			map[r][c] = 0;
			c++;
		}
		r++;
	}
}

static void	set_edges(int **map, int *input, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		map[0][i + 1] = input[i];
		map[length + 1][i + 1] = input[length + i];
		map[i + 1][0] = input[length * 2 + i];
		map[i + 1][length + 1] = input[length * 3 + i];
		i += 1;
	}
}

int	**make_map(int length, char *values)
{
	int	**result;
	int	*input;

	input = parse_values(values, 4 * length);
	if (!input)
		return (NULL);
	result = make_2d_array(length + 2, length + 2);
	if (!result)
		return (NULL);
	fill_zeros(result, length);
	set_edges(result, input, length);
	free(input);
	return (result);
}
