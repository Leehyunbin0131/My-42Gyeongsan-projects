/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:47:07 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/28 13:21:46 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		if (*(str + n) < '0' || *(str + n) > '9')
		{
			return (0);
		}
		n++;
	}
	return (1);
}
