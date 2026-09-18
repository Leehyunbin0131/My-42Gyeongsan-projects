/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:33:01 by lhbwin            #+#    #+#             */
/*   Updated: 2026/05/04 11:50:36 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	maxlen;
	char	*arr;

	slen = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		maxlen = slen - start;
	else
		maxlen = len;
	arr = (char *)malloc((maxlen + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, s + start, maxlen + 1);
	return (arr);
}
