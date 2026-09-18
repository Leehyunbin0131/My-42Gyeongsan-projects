/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:31:56 by lhb               #+#    #+#             */
/*   Updated: 2026/05/04 11:50:45 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	c;

	p = (unsigned char *)ptr;
	c = (unsigned char)value;
	while (num > 0)
	{
		*p = c;
		p++;
		num--;
	}
	return (ptr);
}
