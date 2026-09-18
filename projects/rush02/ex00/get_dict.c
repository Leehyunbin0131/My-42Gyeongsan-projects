/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:49:16 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 20:44:59 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "rush.h"

static void	free_lines(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

static void	free_dicts(t_dict *dicts)
{
	int	i;

	i = 0;
	while (dicts[i].key != NULL)
	{
		free(dicts[i].key);
		free(dicts[i].value);
		i++;
	}
	free(dicts);
}

static t_dict	*make_dict(char *content, int count)
{
	char	**lines;
	t_dict	*dicts;

	lines = (char **)malloc(sizeof(char *) * (count + 1));
	lines[count] = NULL;
	split_lines(lines, content);
	dicts = malloc(sizeof(t_dict) * (count + 1));
	if (get_dict(lines, count, dicts) == -1)
	{
		free_lines(lines, count);
		free(dicts);
		return (NULL);
	}
	if (has_duplicate_key(dicts))
	{
		free_lines(lines, count);
		free_dicts(dicts);
		return (NULL);
	}
	free_lines(lines, count);
	return (dicts);
}

t_dict	*create_dict(char *dict_path)
{
	char	*content;
	t_dict	*dicts;
	int		count;
	int		total;

	count = open_and_count(dict_path, &total);
	if (count < 0)
		return (NULL);
	content = read_content(dict_path, total);
	dicts = make_dict(content, count);
	free(content);
	return (dicts);
}
