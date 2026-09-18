/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:21:03 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 20:46:42 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "rush.h"

int	count_line(char *buffer, int fd, int *total_bytes)
{
	int		a;
	int		count;
	int		i;

	count = 0;
	i = 0;
	*total_bytes = 0;
	a = read(fd, buffer, 1024);
	while (a > 0)
	{
		*total_bytes += a;
		while (i < a)
		{
			if (i > 0 && buffer[i - 1] != '\n' && buffer[i] == '\n')
				count++;
			i++;
		}
		a = read(fd, buffer, 1024);
		i = 0;
	}
	return (count);
}

int	split_lines(char **lines, char *full_content)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	while (full_content[j])
	{
		if (full_content[j] == '\n')
		{
			if (j && full_content[j - 1] != '\n')
				lines[i++] = ft_strndup(&full_content[start], j - start);
			start = j + 1;
		}
		j++;
	}
	if (start < j)
		lines[i++] = ft_strndup(&full_content[start], j - start);
	return (i);
}

int	check(char *str)
{
	int	a;

	a = 0;
	if (!('0' <= str[a] && str[a] <= '9'))
		return (0);
	while ('0' <= str[a] && str[a] <= '9')
		a++;
	while (str[a] != ':')
	{
		if (!(str[a] == ' '))
			return (0);
		a++;
	}
	a++;
	while (str[a] == ' ')
		a++;
	if (!(33 <= str[a] && str[a] <= 126))
		return (0);
	while (str[a] && str[a] != '\n' && (32 <= str[a] && str[a] <= 126))
		a++;
	if (str[a] != '\n' && str[a] != '\0')
		return (0);
	return (1);
}

int	parse_line(char *str, struct s_dict *tmp)
{
	int	j;
	int	a;

	a = 0;
	if (check(str) == 0)
		return (0);
	while (str[a] != ':' && str[a] != ' ')
		a++;
	tmp->key = ft_strndup(str, a);
	if (tmp->key == NULL)
		return (0);
	while (str[a] != ':')
		a++;
	a++;
	while (str[a] == ' ')
		a++;
	j = 0;
	while (str[a + j])
		j++;
	while (j > 0 && str[a + j - 1] == ' ')
		j--;
	tmp->value = ft_strndup(&str[a], j);
	if (tmp->value == NULL)
		return (free(tmp->key), 0);
	return (1);
}

int	get_dict(char **lines, int count, struct s_dict *dicts)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!parse_line(lines[i], &dicts[i]))
			return (-1);
		i++;
	}
	dicts[i].key = NULL;
	return (0);
}
