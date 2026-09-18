/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:33:58 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 20:43:52 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

int	has_duplicate_key(t_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].key != NULL)
	{
		j = i + 1;
		while (dict[j].key != NULL)
		{
			if (ft_strcmp(dict[i].key, dict[j].key) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
