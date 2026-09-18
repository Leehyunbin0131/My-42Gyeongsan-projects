/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:30:11 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/09 19:04:01 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		len;
	int		i;

	len = 0;
	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
		len = len + ft_strlen(strs[i++]);
	len = len + ((size - 1) * ft_strlen(sep));
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr = ft_strcat(arr, strs[i]);
		if (i + 1 != size)
			ft_strcat(arr, sep);
		i++;
	}
	return (arr);
}
