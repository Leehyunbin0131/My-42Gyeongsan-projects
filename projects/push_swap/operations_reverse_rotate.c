/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:16:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(int *stack, int top)
{
	int	tmp;
	int	i;

	if (top < 2)
		return (OP_NONE);
	tmp = stack[0];
	i = 0;
	while (i < top - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[top - 1] = tmp;
	return (OP_RRA);
}

int	rrb(int *stack, int top)
{
	rra(stack, top);
	return (OP_RRB);
}

int	rrr(int *a, int top_a, int *b, int top_b)
{
	rra(a, top_a);
	rrb(b, top_b);
	return (OP_RRR);
}
