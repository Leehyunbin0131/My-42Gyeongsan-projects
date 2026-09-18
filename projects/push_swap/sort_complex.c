/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:14:13 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/27 17:06:13 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_chunks_to_b(t_stack *stacks, int count)
{
	int	next_nbr;
	int	chunk_size;

	chunk_size = (int)(0.05 * stacks->top_a) + 15;
	next_nbr = 0;
	while (next_nbr < count)
	{
		if (next_nbr >= stacks->a[stacks->top_a - 1])
		{
			print_instruction(stacks, pb(stacks->a, &stacks->top_a,
					stacks->b, &stacks->top_b));
			print_instruction(stacks, rb(stacks->b, stacks->top_b));
			next_nbr++;
		}
		else if (next_nbr < stacks->a[stacks->top_a - 1]
			&& (next_nbr + chunk_size) >= stacks->a[stacks->top_a - 1])
		{
			print_instruction(stacks, pb(stacks->a, &stacks->top_a,
					stacks->b, &stacks->top_b));
			next_nbr++;
		}
		else
			print_instruction(stacks, ra(stacks->a, stacks->top_a));
	}
	return (next_nbr);
}

static void	push_sorted_to_a(t_stack *stacks, int next_nbr)
{
	int	index;

	while (next_nbr--)
	{
		while (stacks->b[stacks->top_b - 1] != next_nbr)
		{
			index = find_value_index(stacks->b, stacks->top_b, next_nbr);
			if ((stacks->top_b - 1) / 2 < index)
				print_instruction(stacks, rb(stacks->b, stacks->top_b));
			else
				print_instruction(stacks, rrb(stacks->b, stacks->top_b));
		}
		print_instruction(stacks, pa(stacks->a, &stacks->top_a,
				stacks->b, &stacks->top_b));
	}
}

void	sort_complex(t_stack *stacks)
{
	int	count;
	int	next_nbr;

	count = stacks->top_a;
	next_nbr = push_chunks_to_b(stacks, count);
	push_sorted_to_a(stacks, next_nbr);
}
