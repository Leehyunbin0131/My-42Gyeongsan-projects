/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:55:50 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/20 10:23:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		print_num(int fd, va_list ap);
int		ft_fprintf(int fd, const char *format, ...);

#endif
