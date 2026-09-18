/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 02:09:34 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 02:11:41 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

void	free_dp(int **dp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

int	**init_dp(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = (int **)malloc(sizeof(int *) * rows);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dp[i] = (int *)malloc(sizeof(int) * cols);
		i++;
	}
	return (dp);
}
