/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:09:50 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/09 15:54:10 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	ft_is_prime(int nb)
{
	int	i;
	int	num;

	if (nb == 2)
		return (1);
	if (nb < 2)
		return (0);
	i = 2;
	while (i < nb)
	{
		num = nb % i;
		if (num == 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>
int main()
{
	printf("%d", ft_is_prime(2147483647));
}