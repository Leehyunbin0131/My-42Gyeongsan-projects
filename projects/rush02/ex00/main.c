/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:19:25 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 22:04:26 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

void	free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].key != NULL)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}

int	handle_error(t_dict *dict, int *groups, char *msg)
{
	ft_putstr(msg);
	if (dict != NULL)
		free_dict(dict);
	if (groups != NULL)
		free(groups);
	return (1);
}

int	run_rush(char *dict_path, char *num_str)
{
	t_dict	*dict;
	int		*groups;
	int		group_count;

	group_count = (ft_strlen(num_str) + 2) / 3;
	groups = (int *)malloc(sizeof(int) * group_count);
	if (groups == NULL)
		return (handle_error(NULL, NULL, "Error"));
	dict = create_dict(dict_path);
	if (dict == NULL)
		return (handle_error(NULL, groups, "Dict Error\n"));
	if (print_number(dict, num_str, groups) == 1)
		return (handle_error(dict, groups, "Dict Error\n"));
	ft_putchar('\n');
	free(groups);
	free_dict(dict);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_valid_number(argv[1]))
			return (handle_error(NULL, NULL, "Error"));
		return (run_rush("numbers.dict", skip_zeros(argv[1])));
	}
	else if (argc == 3)
	{
		if (!is_valid_number(argv[2]))
			return (handle_error(NULL, NULL, "Error\n"));
		return (run_rush(argv[1], skip_zeros(argv[2])));
	}
	return (handle_error(NULL, NULL, "Error\n"));
}
