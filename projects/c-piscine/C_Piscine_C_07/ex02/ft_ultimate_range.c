/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:10:53 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/09 18:40:59 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	len;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (NULL);
	}
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len);
	if (arr == NULL)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (len);
}
