/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:14:07 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/04 17:08:25 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		get_base_len(char *base);

int	get_base_len(char *base)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '-' || base[len] == '+')
			return (0);
		len++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	int			num;
	int			i;
	char		str[32];

	len = get_base_len(base);
	if (len < 2)
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	if (nbr < 0)
		write(1, "-", 1);
	i = 0;
	while (nbr != 0)
	{
		num = nbr % len;
		if (num < 0)
			num = num * -1;
		str[++i] = base[num];
		nbr = nbr / len;
	}
	while (i > 0)
		write(1, &str[i--], 1);
	return ;
}
