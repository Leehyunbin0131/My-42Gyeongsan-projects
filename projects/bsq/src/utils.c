/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:12:14 by sumpark           #+#    #+#             */
/*   Updated: 2026/02/08 19:44:03 by sumpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] != '\0' || s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (0);
}

char	*append_str(char *str, char c)
{
	int		idx;
	char	*res;

	idx = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[idx] != '\0')
	{
		res[idx] = str[idx];
		idx++;
	}
	free(str);
	res[idx++] = c;
	res[idx++] = '\0';
	return (res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
