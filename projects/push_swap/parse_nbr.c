/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:31:02 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/27 18:00:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_range(char *str)
{
	int		sign;
	char	*limit;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (*str == '\0')
		return (1);
	if (sign == 1)
		limit = "2147483647";
	else
		limit = "2147483648";
	if (ft_strlen(str) > ft_strlen(limit))
		return (0);
	if (ft_strlen(str) == ft_strlen(limit) && ft_strcmp(str, limit) > 0)
		return (0);
	return (1);
}

static int	check_nbr(char *str)
{
	if (!str || !str[0])
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!str[0])
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	parse_nbr(char *str, int *nbr)
{
	int	i;
	int	sign;
	int	val;

	if (!check_nbr(str) || !in_range(str))
		return (0);
	i = 0;
	sign = 1;
	val = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	*nbr = val * sign;
	return (1);
}
