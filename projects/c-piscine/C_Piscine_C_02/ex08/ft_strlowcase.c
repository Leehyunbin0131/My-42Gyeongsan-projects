/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:44:13 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/01 17:00:18 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		if (*(str + n) >= 'A' && *(str + n) <= 'Z')
		{
			*(str + n) = *(str + n) + 32;
		}
		n++;
	}
	return (str);
}
