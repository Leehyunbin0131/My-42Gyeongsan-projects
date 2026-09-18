/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 20:00:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 21:00:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder_pct(double disorder)
{
	int	value;

	value = (int)(disorder * 10000.0);
	ft_fprintf(2, "[bench] disorder: %d.", value / 100);
	if ((value % 100) < 10)
		ft_fprintf(2, "0");
	ft_fprintf(2, "%d%%\n", value % 100);
}

static void	print_strategy_line(t_stack *stacks)
{
	ft_fprintf(2, "[bench] strategy: ");
	if (stacks->s_type == SIMPLE)
		ft_fprintf(2, "Simple / O(n²)\n");
	else if (stacks->s_type == MEDIUM)
		ft_fprintf(2, "Medium / O(n√n)\n");
	else if (stacks->s_type == COMPLEX)
		ft_fprintf(2, "Complex / O(n√n)\n");
	else if (stacks->disorder < 0.2)
		ft_fprintf(2, "Adaptive / O(n²)\n");
	else if (stacks->disorder < 0.5)
		ft_fprintf(2, "Adaptive / O(n√n)\n");
	else
		ft_fprintf(2, "Adaptive / O(n√n)\n");
}

void	print_bench(t_stack *stacks)
{
	int	total;
	int	i;

	total = 0;
	i = OP_SA;
	while (i <= OP_RRR)
		total += stacks->ops[i++];
	print_disorder_pct(stacks->disorder);
	print_strategy_line(stacks);
	ft_fprintf(2, "[bench] total_ops: %d\n", total);
	ft_fprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		stacks->ops[OP_SA], stacks->ops[OP_SB], stacks->ops[OP_SS],
		stacks->ops[OP_PA], stacks->ops[OP_PB]);
	ft_fprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		stacks->ops[OP_RA], stacks->ops[OP_RB], stacks->ops[OP_RR],
		stacks->ops[OP_RRA], stacks->ops[OP_RRB], stacks->ops[OP_RRR]);
}
