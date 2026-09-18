/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:01:48 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/05 17:47:06 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	k;
	int	num;

	k = 1;
	num = 1;
	if (nb < 0)
		return (0);
	while (k <= nb)
	{
		num = num * k;
		k++;
	}
	return (num);
}
