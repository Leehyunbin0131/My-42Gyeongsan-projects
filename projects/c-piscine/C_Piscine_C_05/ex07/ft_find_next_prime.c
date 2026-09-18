/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:16:17 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/09 15:51:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);

int	is_prime(int nb)
{
	int	i;
	int	num;

	if (nb == 2)
		return (nb);
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
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	int	num;
	int	i;

	while (1)
	{
		num = is_prime(nb);
		if (num)
			return (num);
		nb++;
	}
}
