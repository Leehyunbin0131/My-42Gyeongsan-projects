/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:48:22 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 15:48:37 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cutting(char const *s, char c)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s != c && !flag)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	**inside(char const *s, char c, char **arr)
{
	int	k;
	int	i;
	int	start;

	i = 0;
	k = 0;
	start = 0;
	while (s[k] != '\0')
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		if (s[k] != c && s[k] != '\0')
		{
			start = k;
			while (s[k] != c && s[k] != '\0')
				k++;
			arr[i] = ft_substr(s, start, k - start);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc((cutting(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (inside(s, c, arr));
}
