/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:17:43 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/25 18:24:16 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	m;
	int	n;

	n = 0;
	while (n < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{	
			j = i + 1;
			if (*(tab + i) > *(tab + j))
			{
				m = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = m;
			}
			i++;
		}
		n++;
	}
}
