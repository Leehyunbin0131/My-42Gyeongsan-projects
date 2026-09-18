/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:25:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:25:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	print_instruction_two(int instruction)
{
	if (instruction == OP_RB)
		write(1, "rb\n", 3);
	else if (instruction == OP_RR)
		write(1, "rr\n", 3);
	else if (instruction == OP_RRA)
		write(1, "rra\n", 4);
	else if (instruction == OP_RRB)
		write(1, "rrb\n", 4);
	else if (instruction == OP_RRR)
		write(1, "rrr\n", 4);
}

void	print_instruction(t_stack *stacks, int instruction)
{
	if (instruction == OP_NONE)
		return ;
	if (stacks->bench)
		stacks->ops[instruction]++;
	if (instruction == OP_SA)
		write(1, "sa\n", 3);
	else if (instruction == OP_SB)
		write(1, "sb\n", 3);
	else if (instruction == OP_SS)
		write(1, "ss\n", 3);
	else if (instruction == OP_PA)
		write(1, "pa\n", 3);
	else if (instruction == OP_PB)
		write(1, "pb\n", 3);
	else if (instruction == OP_RA)
		write(1, "ra\n", 3);
	else
		print_instruction_two(instruction);
}
