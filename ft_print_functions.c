/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:43:45 by nali              #+#    #+#             */
/*   Updated: 2021/12/16 11:43:45 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long p)
{
	char	*str;
	int		len;

	if (!p)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	str = ft_convert_to_hex(p);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}

int	ft_print_hex(unsigned long long hex, int x)
{
	char	*str;
	int		len;

	str = NULL;
	if (x == 0)
		str = ft_convert_to_hex(hex);
	else if (x == 1)
		str = ft_touppercase(ft_convert_to_hex(hex));
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_print_number(int num)
{
	char	*s;
	int		len;

	s = ft_itoa(num);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
