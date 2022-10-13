/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:23:25 by nali              #+#    #+#             */
/*   Updated: 2021/12/10 14:23:25 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_check_two(const char *format, va_list args, int *c)
{
	int	count;

	count = *c;
	if (ft_strncmp(format, "p", 1) == 0)
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (ft_strncmp(format, "d", 1) == 0)
		count += ft_print_number(va_arg(args, int));
	else if (ft_strncmp(format, "i", 1) == 0)
		count += ft_print_number(va_arg(args, int));
	else if (ft_strncmp(format, "u", 1) == 0)
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (ft_strncmp(format, "X", 1) == 0)
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (ft_strncmp(format, "x", 1) == 0)
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (ft_strncmp(format, "%", 1) == 0)
	{
		count++;
		ft_putchar_fd('%', 1);
	}
	return (count);
}

int	ft_format_check(const char *format, va_list args, int count)
{
	char	*s;

	if (ft_strncmp(format, "c", 1) == 0)
	{
		count++;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (ft_strncmp(format, "s", 1) == 0)
	{
		s = va_arg(args, char *);
		if (s == NULL)
		{
			count += 6;
			ft_putstr_fd("(null)", 1);
		}
		else
		{
			count += ft_strlen(s);
			ft_putstr_fd(s, 1);
		}
	}
	else
		count = ft_format_check_two(format, args, &count);
	return (count);
}
