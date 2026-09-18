/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:16:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define OP_NONE 0
# define OP_SA 1
# define OP_SB 2
# define OP_SS 3
# define OP_PA 4
# define OP_PB 5
# define OP_RA 6
# define OP_RB 7
# define OP_RR 8
# define OP_RRA 9
# define OP_RRB 10
# define OP_RRR 11

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		top_a;
	int		top_b;
	int		bench;
	int		s_type;
	double	disorder;
	int		ops[12];
}	t_stack;

typedef struct s_nums
{
	char	**args;
	int		count;
	int		split;
}	t_nums;

int		sa(int *stack, int top);
int		sb(int *stack, int top);
int		ss(int *a, int top_a, int *b, int top_b);
int		pa(int *a, int *top_a, int *b, int *top_b);
int		pb(int *a, int *top_a, int *b, int *top_b);
int		ra(int *stack, int top);
int		rb(int *stack, int top);
int		rr(int *a, int top_a, int *b, int top_b);
int		rra(int *stack, int top);
int		rrb(int *stack, int top);
int		rrr(int *a, int top_a, int *b, int top_b);
int		init_stk(t_stack *stacks, char **args, int count);
int		arg_start(t_stack *stacks, int ac, char **av);
int		prep_args(int ac, char **av, int start, t_nums *nums);
int		parse_nbr(char *str, int *nbr);
int		has_dup(int *stack, int top);
int		alloc_stk(t_stack *stacks, int size);
void	free_stacks(t_stack *stacks);
int		is_sorted(int *a, int top);
int		find_value_index(int *stack, int top, int value);
void	print_instruction(t_stack *stacks, int instruction);
void	print_bench(t_stack *stacks);
double	calc_disorder(int *stack, int top);
void	sort_simple(t_stack *stacks);
void	sort_medium(t_stack *stacks);
void	sort_complex(t_stack *stacks);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		arr_len(char **arr);
void	free_split(char **arr);

#endif
