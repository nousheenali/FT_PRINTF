/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hex.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:37:22 by nali              #+#    #+#             */
/*   Updated: 2021/12/09 12:37:22 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_touppercase(char *str)
{
	char	*s;

	s = str;
	while (*s != '\0')
	{
		if (ft_isalpha(*s) != 0)
		{
			if (*s >= 97 && *s <= 122)
				*s = *s - 32;
		}
		s++;
	}
	return (str);
}

char	*ft_convert_to_hex(unsigned long long n)
{
	int					i;
	unsigned long long	num;
	char				*result;
	char				s[17];

	ft_strlcpy(s, "0123456789abcdef", 17);
	i = 0;
	num = n;
	if (num == 0)
		i = 1;
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	result = (char *)malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i] = '\0';
	while (i > 0)
	{
		result[--i] = s[n % 16];
		n = n / 16;
	}
	return (result);
}
