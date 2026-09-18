/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:15:11 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/04 11:50:46 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cpy_s1;
	const unsigned char	*cpy_s2;

	cpy_s1 = (const unsigned char *)s1;
	cpy_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1 && *cpy_s1 == *cpy_s2)
	{
		cpy_s1++;
		cpy_s2++;
		n--;
	}
	return (*cpy_s1 - *cpy_s2);
}
