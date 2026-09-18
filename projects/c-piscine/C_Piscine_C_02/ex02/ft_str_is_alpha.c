/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:23:24 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/28 13:19:38 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		if (*(str + n) >= 'a' && *(str + n) <= 'z')
		{
			n++;
		}
		else if (*(str + n) >= 'A' && *(str + n) <= 'Z')
		{
			n++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
