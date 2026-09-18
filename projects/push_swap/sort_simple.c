/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:16:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_push_to_a(t_stack *stacks, int next_nbr)
{
	while (next_nbr--)
	{
		print_instruction(stacks, pa(stacks->a, &stacks->top_a,
				stacks->b, &stacks->top_b));
	}
}

void	sort_simple(t_stack *stacks)
{
	int	next_nbr;
	int	index;
	int	count;

	count = stacks->top_a;
	next_nbr = 0;
	index = 0;
	while (next_nbr < count)
	{
		while (stacks->a[stacks->top_a - 1] != next_nbr)
		{
			index = find_value_index(stacks->a, stacks->top_a, next_nbr);
			if ((stacks->top_a - 1) / 2 < index)
				print_instruction(stacks, ra(stacks->a, stacks->top_a));
			else
			{
				print_instruction(stacks, rra(stacks->a, stacks->top_a));
			}
		}
		print_instruction(stacks, pb(stacks->a, &stacks->top_a,
				stacks->b, &stacks->top_b));
		next_nbr++;
	}
	all_push_to_a(stacks, next_nbr);
}
