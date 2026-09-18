/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:09:46 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/25 14:01:35 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	long long	m;
	char		a;

	m = nb;
	if (m < 0)
	{
		write(1, "-", 1);
		m = m * -1;
	}
	if (m >= 10)
	{
		ft_putnbr(m / 10);
	}
	a = 48 + (m % 10);
	write(1, &a, 1);
}

int main()
{
	ft_putnbr(1234);
}