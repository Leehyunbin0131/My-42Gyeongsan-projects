/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:25:07 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/28 13:19:58 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		if (*(str + n) < 'a' || *(str + n) > 'z')
		{
			return (0);
		}
		n++;
	}
	return (1);
}
