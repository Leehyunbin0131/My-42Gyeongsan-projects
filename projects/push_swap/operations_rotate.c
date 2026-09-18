/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:16:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(int *stack, int top)
{
	int	tmp;
	int	i;

	if (top < 2)
		return (OP_NONE);
	tmp = stack[top - 1];
	i = top - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
	return (OP_RA);
}

int	rb(int *stack, int top)
{
	ra(stack, top);
	return (OP_RB);
}

int	rr(int *a, int top_a, int *b, int top_b)
{
	ra(a, top_a);
	rb(b, top_b);
	return (OP_RR);
}
