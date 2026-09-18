/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:06:48 by lhb               #+#    #+#             */
/*   Updated: 2026/05/04 11:50:41 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	s_len;

	s_len = ft_strlen(s1);
	arr = (char *)malloc((s_len + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	ft_memcpy(arr, s1, s_len + 1);
	return (arr);
}
