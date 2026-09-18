/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:43:27 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/05 16:34:48 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_power(int nb, int power);
int	ft_power(int nb, int power, int num);

int	ft_power(int nb, int power, int num)
{
	if (power < 1)
		return (num);
	num = num * nb;
	return (ft_power(nb, power - 1, num));
}

int	ft_recursive_power(int nb, int power)
{
	int	num;

	num = 1;
	if (power < 0)
		return (0);
	return (ft_power(nb, power, num));
}
