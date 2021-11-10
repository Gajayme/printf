/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:47:10 by gajayme           #+#    #+#             */
/*   Updated: 2021/11/10 18:06:46 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	distributor(char spec, void *param, size_t *symb)
{
	if (!param && (spec == 's'))
		ft_putstr_fd("(null)", 1, symb);
	else if (spec == 'c' || spec == '%')
		ft_putchar_fd((char)param, 1, symb);
	else if (spec == 's')
		ft_putstr_fd((char *)param, 1, symb);
	else if (spec == 'p' && ft_putstr_fd("0x", 1, symb))
		ft_putnbr_base_p((unsigned long int)param, 16, "0123456789abcdef",
			 symb);
	else if (spec == 'd' || spec == 'i')
		putnbr_abs((long int)param, 10, "0123456789", symb);
	else if (spec == 'u')
		ft_putnbr_base((unsigned int)param, 10, "0123456789", symb);
	else if (spec == 'x')
		ft_putnbr_base((unsigned int)param, 16, "0123456789abcdef", symb);
	else if (spec == 'X')
		ft_putnbr_base((unsigned int)param, 16, "0123456789ABCDEF", symb);
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	size_t	symb;

	symb = 0;
	va_start(param, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar_fd(*str, 1, &symb);
		else if (*str == '%' && *str++ && *str != '%')
			distributor(*str, va_arg(param, void *), &symb);
		else if (*str == '%' && *str)
			ft_putchar_fd('%', 1, &symb);
		str ++;
	}
	va_end(param);
	return (symb);
}
