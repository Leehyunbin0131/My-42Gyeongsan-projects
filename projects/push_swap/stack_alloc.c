/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:00:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/18 20:00:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alloc_stk(t_stack *stacks, int size)
{
	stacks->a = (int *)malloc(sizeof(int) * size);
	if (!stacks->a)
		return (0);
	stacks->b = (int *)malloc(sizeof(int) * size);
	if (!stacks->b)
	{
		free(stacks->a);
		return (0);
	}
	return (1);
}

int	has_dup(int *stack, int top)
{
	int	i;
	int	j;

	i = 0;
	while (i < top - 1)
	{
		j = i + 1;
		while (j < top)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
