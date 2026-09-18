/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:17:06 by chwang            #+#    #+#             */
/*   Updated: 2026/02/01 15:42:32 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*make_1d_array(int size)
{	
	if (size < 1)
		return (0);
	return ((int *)malloc((size_t)size * sizeof(int)));
}

int	**make_2d_array(int rows, int cols)
{
	int	**map;
	int	i;

	map = (int **)malloc((size_t)rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		map[i] = make_1d_array(cols);
		i++;
	}
	return (map);
}
