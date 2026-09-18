/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:46:35 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/04 17:45:41 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
int		set_count(int *count);
void	skip_pt_1(char *str, int *k);
void	skip_pt_2(char *str, int *k, int *count);

void	skip_pt_1(char *str, int *k)
{
	int	p;

	p = *k;
	while ((str[p] >= 9 && str[p] <= 13) || str[p] == ' ')
	{
		p++;
	}
	*k = p;
}

void	skip_pt_2(char *str, int *k, int *count)
{
	int	p;

	p = *k;
	while (str[p] != '\0' && (str[p] < '0' || str[p] > '9'))
	{
		if (str[p] == '-')
		{
			*count = *count + 1;
		}
		else if (str[p] != '+' && str[p] != '-')
			*count = 0;
		p++;
	}
	*k = p;
}

int	set_count(int *count)
{
	int	pos;

	if (*count == 0 || *count % 2 == 0)
		pos = 1;
	else
		pos = -1;
	return (pos);
}

int	ft_atoi(char *str)
{
	int	k;
	int	count;
	int	pos;
	int	num;

	num = 0;
	count = 0;
	k = 0;
	skip_pt_1(str, &k);
	skip_pt_2(str, &k, &count);
	pos = set_count(&count);
	while (str[k] != '\0')
	{
		if (str[k] != '\0' && (str[k] < '0' || str[k] > '9'))
			break ;
		num = num * 10;
		num = num + (str[k] - '0');
		k++;
	}
	num = num * pos;
	return (num);
}
