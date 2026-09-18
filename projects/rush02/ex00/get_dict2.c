/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:44:47 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 20:45:35 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "rush.h"

int	open_and_count(char *dict_path, int *total)
{
	char	buffer[1024];
	int		fd;
	int		count;

	fd = open(dict_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = count_line(buffer, fd, total);
	close(fd);
	return (count);
}

char	*read_content(char *dict_path, int total)
{
	char	*content;
	int		fd;

	fd = open(dict_path, O_RDONLY);
	content = (char *)malloc(total + 1);
	read(fd, content, total);
	content[total] = '\0';
	close(fd);
	return (content);
}
