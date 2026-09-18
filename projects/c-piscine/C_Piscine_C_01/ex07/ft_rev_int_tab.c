/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 00:06:31 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/25 18:03:53 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int	t;
	int	f;
	int	l;

	n = 0;
	while (n < size / 2)
	{		
		f = *(tab + n);
		l = *tab + (size - n - 1);
		*(tab + (size - n - 1)) = f;
		*(tab + n) = l;
		n++;
	}
}
