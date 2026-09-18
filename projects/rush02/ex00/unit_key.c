/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:23:41 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 17:13:48 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

char	*make_unit_key(int index)
{
	char	*key;
	int		i;
	int		zeros;

	if (index <= 0)
		return (NULL);
	zeros = index * 3;
	key = (char *)malloc(sizeof(char) * (zeros + 2));
	if (key == NULL)
		return (NULL);
	key[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	return (key);
}

int	print_unit(t_dict *dict, int i)
{
	char	*unit_key;
	char	*unit_word;

	unit_key = make_unit_key(i);
	if (unit_key != NULL)
	{
		unit_word = get_word(dict, unit_key);
		if (unit_word == NULL)
		{
			free(unit_key);
			return (1);
		}
		ft_putchar(' ');
		ft_putstr(unit_word);
		free(unit_key);
	}
	return (0);
}
