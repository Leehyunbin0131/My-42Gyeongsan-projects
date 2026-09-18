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
int		print_char(va_list ap);
int		print_str(va_list ap);
int		print_num(va_list ap);
int		print_unsigned(char type, va_list ap);
int		put_unsigned_base(unsigned int nbr, char *base_str);
int		put_ptr_base(unsigned long long nbr, char *base_str);
int		print_mem(va_list ap);
int		ft_printf(const char *format, ...);

#endif