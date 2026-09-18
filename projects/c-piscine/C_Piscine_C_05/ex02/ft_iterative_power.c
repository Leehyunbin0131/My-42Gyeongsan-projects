/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:33:59 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/05 17:57:15 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	num;
	int	i;

	i = 0;
	num = 1;
	if (power < 0)
		return (0);
	while (i < power)
	{
		num = num * nb;
		i++;
	}
	return (num);
}
