/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:39:55 by nali              #+#    #+#             */
/*   Updated: 2021/11/07 09:41:55 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_putnbr_unsigned(unsigned int n);
char	*ft_convert_to_hex(unsigned long long n);
char	*ft_touppercase(char *str);
int		ft_format_check(const char *format, va_list args, int count);
int		ft_print_ptr(unsigned long long p);
int		ft_print_hex(unsigned long long hex, int x);
int		ft_print_number(int num);
int		ft_printf(const char *format, ...);

#endif
