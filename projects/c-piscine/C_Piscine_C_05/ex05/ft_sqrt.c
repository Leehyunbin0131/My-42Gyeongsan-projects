/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:53:42 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/05 17:57:40 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if (nb == 1)
		return (1);
	while (i < nb)
	{
		num = i * i;
		if (num == nb)
			return (i);
		i++;
	}
	return (0);
}
