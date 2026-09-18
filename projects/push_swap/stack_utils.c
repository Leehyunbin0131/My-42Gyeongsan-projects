/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:16:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stacks)
{
	free(stacks->a);
	free(stacks->b);
}

int	is_sorted(int *a, int top)
{
	int	i;

	i = 0;
	while (i < top - 1)
	{
		if (a[i] <= a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_value_index(int *stack, int top, int value)
{
	int	index;

	index = 0;
	while (index < top && stack[index] != value)
		index++;
	return (index);
}

double	calc_disorder(int *stack, int top)
{
	int		i;
	int		j;
	int		inv;
	int		total;

	if (top <= 1)
		return (0.0);
	inv = 0;
	i = 0;
	while (i < top)
	{
		j = i + 1;
		while (j < top)
		{
			if (stack[top - 1 - i] > stack[top - 1 - j])
				inv++;
			j++;
		}
		i++;
	}
	total = top * (top - 1) / 2;
	return ((double)inv / (double)total);
}
