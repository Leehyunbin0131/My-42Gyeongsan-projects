/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:14:22 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/25 13:14:57 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int a, int b);
void	ft_print_comb2(void);

void	ft_print(int a, int b)
{
	char	pr[4];

	pr[0] = 48 + (a / 10);
	pr[1] = 48 + (a % 10);
	pr[2] = 48 + (b / 10);
	pr[3] = 48 + (b % 10);
	write(1, &pr[0], 1);
	write(1, &pr[1], 1);
	write(1, " ", 1);
	write(1, &pr[2], 1);
	write(1, &pr[3], 1);
	if (a != 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	n[2];

	n[0] = 0;
	while (n[0] <= 99)
	{
		n[1] = n[0] + 1;
		while (n[1] <= 99)
		{
			ft_print(n[0], n[1]);
			n[1]++;
		}
		n[0]++;
	}
}
