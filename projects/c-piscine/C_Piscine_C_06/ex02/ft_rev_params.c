/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:25:47 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/05 15:21:38 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	main(int ag, char *av[])
{
	int	k;
	int	n;

	k = ag - 1;
	if (ag < 2)
		return (0);
	while (k > 0)
	{
		n = ft_strlen(av[k]);
		write(1, av[k], n);
		write(1, "\n", 1);
		k--;
	}
	return (0);
}
