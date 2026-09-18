/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:01:03 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/04 11:50:47 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		match;

	ptr = (const unsigned char *)s;
	match = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == match)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
