/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:59:30 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 21:00:14 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

int	validate_unit(t_dict *dict, int i)
{
	char	*unit_key;
	char	*unit_word;

	unit_key = make_unit_key(i);
	if (unit_key != NULL)
	{
		unit_word = get_word(dict, unit_key);
		free(unit_key);
		if (unit_word == NULL)
			return (1);
	}
	return (0);
}
