/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:16:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(int *stack, int top)
{
	int	tmp;

	if (top < 2)
		return (OP_NONE);
	tmp = stack[top - 1];
	stack[top - 1] = stack[top - 2];
	stack[top - 2] = tmp;
	return (OP_SA);
}

int	sb(int *stack, int top)
{
	sa(stack, top);
	return (OP_SB);
}

int	ss(int *a, int top_a, int *b, int top_b)
{
	sa(a, top_a);
	sb(b, top_b);
	return (OP_SS);
}

int	pa(int *a, int *top_a, int *b, int *top_b)
{
	if (*top_b == 0)
		return (OP_NONE);
	a[*top_a] = b[*top_b - 1];
	(*top_a)++;
	(*top_b)--;
	return (OP_PA);
}

int	pb(int *a, int *top_a, int *b, int *top_b)
{
	if (*top_a == 0)
		return (OP_NONE);
	b[*top_b] = a[*top_a - 1];
	(*top_b)++;
	(*top_a)--;
	return (OP_PB);
}
