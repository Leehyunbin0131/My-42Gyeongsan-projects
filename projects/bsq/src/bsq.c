/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 02:08:08 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 11:10:20 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void	fill_result(int **map, int *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info[0])
	{
		j = 0;
		while (j < info[0])
		{
			map[info[1] - i][info[2] - j] = 9;
			j++;
		}
		i++;
	}
}

int	get_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	calc_cell(int **map, int **dp, int *p, int *info)
{
	if (map[p[0]][p[1]] == 1)
		dp[p[0]][p[1]] = 0;
	else if (p[0] == 0 || p[1] == 0)
		dp[p[0]][p[1]] = 1;
	else
		dp[p[0]][p[1]] = get_min(dp[p[0] - 1][p[1]], dp[p[0]][p[1] - 1],
				dp[p[0] - 1][p[1] - 1]) + 1;
	if (dp[p[0]][p[1]] > info[0])
	{
		info[0] = dp[p[0]][p[1]];
		info[1] = p[0];
		info[2] = p[1];
	}
}

void	find_bsq_dp(int **map, int *size)
{
	int	**dp;
	int	pos[2];
	int	info[3];

	dp = init_dp(size[0], size[1]);
	info[0] = 0;
	info[1] = 0;
	info[2] = 0;
	pos[0] = 0;
	while (pos[0] < size[0])
	{
		pos[1] = 0;
		while (pos[1] < size[1])
		{
			calc_cell(map, dp, pos, info);
			pos[1]++;
		}
		pos[0]++;
	}
	fill_result(map, info);
	free_dp(dp, size[0]);
}
