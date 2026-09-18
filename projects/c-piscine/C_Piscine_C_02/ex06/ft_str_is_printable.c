/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:41:13 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/28 15:25:26 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		if (*(str + n) < 32 || *(str + n) > 126)
		{
			return (0);
		}
		n++;
	}
	return (1);
}
