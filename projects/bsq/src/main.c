/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 02:20:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 21:09:37 by sumpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "map_reader.h"
#include "utils.h"
#include "bsq.h"

void	print_map(int **map, int *size, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			if (map[i][j] == 9)
				ft_putchar(set[0]);
			else if (map[i][j] == 1)
				ft_putchar(set[1]);
			else
				ft_putchar(set[2]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	free_map(int **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

void	process_map(int **map, int *size, char *set, int has_next)
{
	if (map == NULL)
	{
		ft_putstr("map error\n");
		if (has_next)
			ft_putchar('\n');
	}
	else
	{
		find_bsq_dp(map, size);
		print_map(map, size, set);
		if (has_next)
			ft_putchar('\n');
		free_map(map);
	}
}

void	handle_map(char *filename, int has_next)
{
	int		size[2];
	char	set[3];
	int		**map;
	int		fd;

	size[0] = 0;
	size[1] = 0;
	if (filename == NULL)
		fd = 0;
	else
		fd = open(filename, O_RDONLY);
	map = read_map(fd, size, set);
	if (filename != NULL)
		close(fd);
	process_map(map, size, set, has_next);
}

int	main(int argc, char *argv[])
{
	int		i;

	if (argc < 2)
		handle_map(NULL, 0);
	else
	{
		i = 1;
		while (i < argc)
		{
			handle_map(argv[i], argv[i + 1] != NULL);
			i++;
		}
	}
	return (0);
}
