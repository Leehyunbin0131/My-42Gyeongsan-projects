/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:54:28 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 21:00:02 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

static int	validate_under_20(t_dict *dict, int n)
{
	char	key[3];

	key[0] = '0' + (n / 10);
	key[1] = '0' + (n % 10);
	key[2] = '\0';
	if (key[0] == '0')
		return (get_word(dict, key + 1) == NULL);
	return (get_word(dict, key) == NULL);
}

static int	validate_tens(t_dict *dict, int n)
{
	char	key[3];

	key[0] = '0' + (n / 10);
	key[1] = '0';
	key[2] = '\0';
	if (get_word(dict, key) == NULL)
		return (1);
	if (n % 10 != 0)
	{
		key[0] = '0' + (n % 10);
		key[1] = '\0';
		if (get_word(dict, key) == NULL)
			return (1);
	}
	return (0);
}

static int	validate_under_100(t_dict *dict, int n)
{
	if (n == 0)
		return (0);
	if (n < 20)
		return (validate_under_20(dict, n));
	return (validate_tens(dict, n));
}

static int	validate_group(t_dict *dict, int n)
{
	char	key[2];

	if (n == 0)
		return (0);
	if (n >= 100)
	{
		key[0] = '0' + (n / 100);
		key[1] = '\0';
		if (get_word(dict, key) == NULL)
			return (1);
		if (get_word(dict, "100") == NULL)
			return (1);
		n = n % 100;
	}
	return (validate_under_100(dict, n));
}

int	validate_number(t_dict *dict, char *str, int *groups)
{
	int	count;
	int	i;

	if (str[0] == '0' && str[1] == '\0')
		return (get_word(dict, "0") == NULL);
	count = split_number(str, groups);
	i = count - 1;
	while (i >= 0)
	{
		if (groups[i] != 0)
		{
			if (validate_group(dict, groups[i]) == 1)
				return (1);
			if (validate_unit(dict, i) == 1)
				return (1);
		}
		i--;
	}
	return (0);
}
