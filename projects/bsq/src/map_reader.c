/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:03:52 by sumpark           #+#    #+#             */
/*   Updated: 2026/02/08 19:40:08 by sumpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "header_parse.h"
#include "utils.h"

int	read_file_header(int fd, int *size, char *set)
{
	char	*res;
	int		status;

	res = read_single_line(fd);
	status = parse_header(res, size, set);
	free(res);
	if (status < 0)
		return (-1);
	return (0);
}

int	**append_map_line(int	*entry, int **map)
{
	int	**res;
	int	idx;

	idx = 0;
	while (map[idx] != NULL)
		idx++;
	res = (int **)malloc(sizeof(int *) * (idx + 2));
	idx = 0;
	while (map[idx] != NULL)
	{
		res[idx] = map[idx];
		idx++;
	}
	free(map);
	res[idx++] = entry;
	res[idx] = NULL;
	return (res);
}

int	conv_to_int_mapline(char *set, char *cline, int *iline)
{
	int	idx;

	idx = 0;
	while ((cline[idx] != '\0') && (cline[idx] != '\n'))
	{
		if (cline[idx] == set[1])
			iline[idx] = 1;
		else if (cline[idx] == set[2])
			iline[idx] = 0;
		else
			return (-1);
		idx++;
	}
	return (idx);
}

int	*get_int_mapline(int fd, int *size, char *set)
{
	int		*res;
	char	*temp;

	if (!size[1])
	{
		temp = read_single_line(fd);
		size[1] = ft_strlen(temp);
	}
	else
		temp = read_single_line_fast(fd, size[1] + 1);
	res = (int *)malloc(sizeof(int) * (size[1]));
	if (conv_to_int_mapline(set, temp, res) != size[1])
	{
		free(res);
		free(temp);
		return (NULL);
	}
	free(temp);
	return (res);
}

int	**read_map(int fd, int *size, char *set)
{
	int	idx;
	int	*temp;
	int	**res;

	if ((fd < 0) || (read_file_header(fd, size, set) < 0))
		return (NULL);
	res = (int **)malloc(sizeof(int *));
	res[0] = NULL;
	idx = 0;
	while (idx < size[0])
	{
		temp = get_int_mapline(fd, size, set);
		if (temp == NULL)
		{
			idx = 0;
			while (res[idx] != NULL)
				free(res[idx++]);
			free(res);
			return (NULL);
		}
		res = append_map_line(temp, res);
		idx++;
	}
	return (res);
}
