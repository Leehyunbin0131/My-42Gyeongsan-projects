/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:13:43 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/05 17:45:28 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb);

int	factorial(int nb, int k, int num)
{
	if (k > nb)
		return (num);
	else
	{
		num = num * k;
		k++;
		return (factorial(nb, k, num));
	}
	return (0);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	return (factorial(nb, 1, 1));
}
