/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 21:30:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 21:30:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_sort(t_stack *stacks, char **av, int i)
{
	if (!ft_strcmp(av[i], "--simple"))
		stacks->s_type = SIMPLE;
	else if (!ft_strcmp(av[i], "--medium"))
		stacks->s_type = MEDIUM;
	else if (!ft_strcmp(av[i], "--complex"))
		stacks->s_type = COMPLEX;
	else if (!ft_strcmp(av[i], "--adaptive"))
		stacks->s_type = ADAPTIVE;
	else
		return (0);
	return (1);
}

static void	init_stacks(t_stack *stacks)
{
	int	i;

	stacks->bench = 0;
	stacks->s_type = ADAPTIVE;
	i = 0;
	while (i < 12)
		stacks->ops[i++] = 0;
}

static int	parse_flags(t_stack *stacks, char **av, int i)
{
	int	strategy_set;

	strategy_set = 0;
	while (av[i] && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!ft_strcmp(av[i], "--bench"))
		{
			if (stacks->bench)
				return (-1);
			stacks->bench = 1;
		}
		else if (!set_sort(stacks, av, i))
			return (-1);
		else if (strategy_set)
			return (-1);
		else
			strategy_set = 1;
		i++;
	}
	return (i);
}

int	arg_start(t_stack *stacks, int ac, char **av)
{
	int	ret;

	if (ac < 2)
		return (0);
	init_stacks(stacks);
	ret = parse_flags(stacks, av, 1);
	if (ret < 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (ret);
}

int	prep_args(int ac, char **av, int start, t_nums *nums)
{
	if (ac - start == 1)
	{
		nums->args = ft_split(av[start], ' ');
		nums->split = 1;
		if (!nums->args)
			return (0);
		nums->count = arr_len(nums->args);
		if (nums->count == 0)
		{
			free_split(nums->args);
			return (0);
		}
		return (1);
	}
	nums->split = 0;
	nums->count = ac - start;
	nums->args = &av[start];
	return (1);
}
