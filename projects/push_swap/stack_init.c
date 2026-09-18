/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*cpy_stack(int *stack, int top)
{
	int	i;
	int	*cpy;

	cpy = malloc(sizeof(int) * top);
	if (!cpy)
		return (0);
	i = 0;
	while (i < top)
	{
		cpy[i] = stack[i];
		i++;
	}
	return (cpy);
}

static int	normalize(int *stack, int top)
{
	int	*cpy;
	int	i;
	int	j;

	cpy = cpy_stack(stack, top);
	if (!cpy)
		return (0);
	i = 0;
	while (i < top)
	{
		j = 0;
		stack[i] = 0;
		while (j < top)
			stack[i] += (cpy[j++] < cpy[i]);
		i++;
	}
	free(cpy);
	return (1);
}

static int	fill_a(char **args, int count, int *stack)
{
	int	i;
	int	current_index;
	int	nbr;

	i = 0;
	current_index = count - 1;
	while (i < count)
	{
		if (!parse_nbr(args[i], &nbr))
			return (0);
		stack[current_index] = nbr;
		current_index--;
		i++;
	}
	return (count);
}

static void	fill_b(int size, int *stack)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i] = 0;
		i++;
	}
}

int	init_stk(t_stack *stacks, char **args, int count)
{
	if (count <= 0)
		return (0);
	if (!alloc_stk(stacks, count))
		return (0);
	stacks->top_a = fill_a(args, count, stacks->a);
	if (!stacks->top_a)
	{
		free_stacks(stacks);
		return (0);
	}
	if (has_dup(stacks->a, stacks->top_a))
	{
		free_stacks(stacks);
		return (0);
	}
	fill_b(count, stacks->b);
	stacks->top_b = 0;
	if (!normalize(stacks->a, stacks->top_a))
	{
		free_stacks(stacks);
		return (0);
	}
	return (1);
}
