/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:36:44 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/04 11:50:37 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		k = 0;
		while (i + k < len && haystack[i + k] == needle[k])
		{
			if (needle[k] == '\0')
				return ((char *)&haystack[i]);
			k++;
		}
		if (needle[k] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
