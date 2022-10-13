/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:06:52 by nali              #+#    #+#             */
/*   Updated: 2021/12/08 15:06:52 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned_recursive(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putchar_fd((n % 10 + '0'), 1);
	}
	if (n <= 9)
	{
		ft_putchar_fd((n + '0'), 1);
	}
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	ft_putnbr_unsigned_recursive(n);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
