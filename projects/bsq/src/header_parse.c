/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:30:58 by sumpark           #+#    #+#             */
/*   Updated: 2026/02/08 19:44:29 by sumpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

char	*cat_str(char *str, char *str2)
{
	int		idx;
	int		idx2;
	char	*res;

	idx = 0;
	idx2 = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(str2) + 1));
	while (str[idx2] != '\0')
	{
		res[idx] = str[idx2];
		idx++;
		idx2++;
	}
	idx2 = 0;
	while (str2[idx2] != '\0')
	{
		res[idx] = str2[idx2];
		idx++;
		idx2++;
	}
	res[idx] = '\0';
	free(str);
	return (res);
}

char	*read_single_line(int fd)
{
	char	*res;
	char	buffer;

	res = (char *)malloc(sizeof(char));
	res[0] = '\0';
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			break ;
		res = append_str(res, buffer);
	}
	return (res);
}

char	*read_single_line_fast(int fd, int size)
{
	int		rem;
	char	*res;
	int		status;
	char	buffer[4096];

	rem = size;
	res = (char *)malloc(sizeof(char));
	res[0] = '\0';
	while (1)
	{
		if (rem > 4095)
			status = read(fd, &buffer, 4095);
		else
			status = read(fd, &buffer, rem);
		if (status < 0)
			break ;
		buffer[status] = '\0';
		res = cat_str(res, buffer);
		rem -= 4095;
		if (rem < 0)
			break ;
	}
	return (res);
}

int	get_charset(char *header, char *set)
{
	int	idx;
	int	idx2;
	int	len;

	len = ft_strlen(header);
	if (len < 4)
		return (-1);
	idx = len - 1;
	idx2 = 0;
	while (idx >= (len - 3))
	{
		if (!(header[idx] >= ' ' && header[idx] <= '~'))
			return (-1);
		set[idx2] = header[idx];
		idx--;
		idx2++;
	}
	return (0);
}

int	parse_header(char *header, int *size, char *set)
{
	int	idx;
	int	len;

	size[0] = 0;
	if (get_charset(header, set) < 0)
		return (-1);
	len = ft_strlen(header) - 4;
	idx = 0;
	while (idx <= len)
	{
		if (!(header[idx] >= '0' && header[idx] <= '9'))
			return (-1);
		size[0] = size[0] * 10 + header[idx] - '0';
		idx++;
	}
	return (0);
}
