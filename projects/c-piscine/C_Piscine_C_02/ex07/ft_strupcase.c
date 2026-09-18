/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:44:13 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/01 14:18:06 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		if (*(str + n) >= 'a' && *(str + n) <= 'z')
		{
			*(str + n) = *(str + n) - 32;
		}
		n++;
	}
	return (str);
}
