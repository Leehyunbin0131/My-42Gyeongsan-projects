/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:18:13 by sumpark           #+#    #+#             */
/*   Updated: 2026/02/08 18:57:55 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PARSE_H
# define HEADER_PARSE_H 1

char	*read_single_line(int fd);
char	*read_single_line_fast(int fd, int size);
int		parse_header(char *header, int *size, char *set);
#endif
