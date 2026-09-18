/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:47:15 by chwang            #+#    #+#             */
/*   Updated: 2026/02/01 19:47:16 by chwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**make_2d_array(int rows, int cols);

int	**make_sequence(int **map, int size)
{
	int	**seq;
	int	i;

	seq = make_2d_array(size, 2);
	i = 0;
	while (i < size)
	{
		seq[i][0] = i + 1;
		seq[i][1] = map[i + 1][0] + map[i + 1][size + 1];
		i++;
	}
	return (seq);
}
