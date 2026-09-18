/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhb <lhb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 21:30:43 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/06 14:14:50 by lhb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_curr_len;
	size_t	slen;
	size_t	i;

	dst_curr_len = 0;
	while (dst_curr_len < dstsize && dst[dst_curr_len])
		dst_curr_len++;
	slen = ft_strlen(src);
	if (dstsize <= dst_curr_len)
		return (dstsize + slen);
	i = 0;
	while (src[i] && (dst_curr_len + i) < (dstsize - 1))
	{
		dst[dst_curr_len + i] = src[i];
		i++;
	}
	dst[dst_curr_len + i] = '\0';
	return (dst_curr_len + slen);
}
