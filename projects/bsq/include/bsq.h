/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 02:20:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 02:20:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>

void	free_dp(int **dp, int rows);
int		**init_dp(int rows, int cols);
void	find_bsq_dp(int **map, int *size);
void	fill_result(int **map, int *info);
int		get_min(int a, int b, int c);
void	calc_cell(int **map, int **dp, int *p, int *info);
#endif
