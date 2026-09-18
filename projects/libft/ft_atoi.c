/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:33:35 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/04 11:50:54 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	flag;
	int	num;

	num = 0;
	flag = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || (*nptr) == '-')
	{
		if (*nptr == '-')
			flag = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
	{
		num = (*nptr - 48) + (num * 10);
		nptr++;
	}
	return (num * flag);
}
