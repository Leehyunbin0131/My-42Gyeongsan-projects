/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:19:25 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 21:01:48 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

int	parse_group(char *str, int start, int len)
{
	int	num;
	int	i;

	num = 0;
	i = start;
	while (i < len)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	split_number(char *str, int *groups)
{
	int	len;
	int	count;
	int	start;

	len = ft_strlen(str);
	count = 0;
	while (len > 0)
	{
		start = len - 3;
		if (start < 0)
			start = 0;
		groups[count] = parse_group(str, start, len);
		count++;
		len = start;
	}
	return (count);
}

int	print_one_group(t_dict *dict, int group, int i, int *printed)
{
	if (*printed)
		ft_putchar(' ');
	if (print_group(dict, group) == 1)
		return (1);
	if (print_unit(dict, i) == 1)
		return (1);
	*printed = 1;
	return (0);
}

int	print_number(t_dict *dict, char *str, int *groups)
{
	int		count;
	int		i;
	int		printed;

	if (validate_number(dict, str, groups) == 1)
		return (1);
	printed = 0;
	if (str[0] == '0' && str[1] == '\0')
	{
		ft_putstr(get_word(dict, "0"));
		return (0);
	}
	count = split_number(str, groups);
	i = count - 1;
	while (i >= 0)
	{
		if (groups[i] != 0)
			print_one_group(dict, groups[i], i, &printed);
		i--;
	}
	return (0);
}
