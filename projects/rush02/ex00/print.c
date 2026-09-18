/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:19:25 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 16:56:18 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

int	print_under_20(t_dict *dict, int n)
{
	char	key[3];
	char	*word;

	key[0] = '0' + (n / 10);
	key[1] = '0' + (n % 10);
	key[2] = '\0';
	if (key[0] == '0')
		word = get_word(dict, key + 1);
	else
		word = get_word(dict, key);
	if (word == NULL)
		return (1);
	ft_putstr(word);
	return (0);
}

int	print_tens(t_dict *dict, int n)
{
	char	key[3];
	char	*word;

	key[0] = '0' + (n / 10);
	key[1] = '0';
	key[2] = '\0';
	word = get_word(dict, key);
	if (word == NULL)
		return (1);
	ft_putstr(word);
	if (n % 10 != 0)
	{
		key[0] = '0' + (n % 10);
		key[1] = '\0';
		word = get_word(dict, key);
		if (word == NULL)
			return (1);
		ft_putchar(' ');
		ft_putstr(word);
	}
	return (0);
}

int	print_under_100(t_dict *dict, int n)
{
	if (n == 0)
		return (0);
	if (n < 20)
		return (print_under_20(dict, n));
	return (print_tens(dict, n));
}

int	print_hundred(t_dict *dict, int n)
{
	char	key[2];
	char	*word;

	key[0] = '0' + (n / 100);
	key[1] = '\0';
	word = get_word(dict, key);
	if (word == NULL)
		return (1);
	ft_putstr(word);
	ft_putchar(' ');
	word = get_word(dict, "100");
	if (word == NULL)
		return (1);
	ft_putstr(word);
	if (n % 100 != 0)
		ft_putchar(' ');
	return (0);
}

int	print_group(t_dict *dict, int n)
{
	if (n == 0)
		return (0);
	if (n >= 100)
	{
		if (print_hundred(dict, n) == 1)
			return (1);
		n = n % 100;
	}
	return (print_under_100(dict, n));
}
