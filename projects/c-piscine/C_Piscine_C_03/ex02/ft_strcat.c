/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:18:42 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/29 16:05:42 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src);

char	*ft_strcat(char *dest, char *src)
{
	int	n;
	int	m;

	n = 0;
	m = 0;
	while (dest[n] != '\0')
	{
		n++;
	}
	while (src[m] != '\0')
	{
		dest[n] = src[m];
		n++;
		m++;
	}
	*(dest + n) = '\0';
	return (dest);
}
