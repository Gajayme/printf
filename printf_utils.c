/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:44:09 by gajayme           #+#    #+#             */
/*   Updated: 2021/11/10 18:10:14 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd, size_t *symb)
{
	if (!s)
		return (0);
	while (*s)
	{
		write(fd, s, 1);
		*symb = *symb + 1;
		s += 1;
	}
	return (1);
}

void	ft_putchar_fd(char c, int fd, size_t *symb)
{
	write(fd, &c, 1);
	*symb = *symb + 1;
}

void	ft_putnbr_base_p(unsigned long int num, unsigned int base,
	 char *charset,
		 size_t *symb)
{
	if (num >= base)
		ft_putnbr_base(num / base, base, charset, symb);
	write(1, &charset[num % base], 1);
	*symb = *symb + 1;
}

void	ft_putnbr_base(long int num, int base, char *charset, size_t *symb)
{
	if (num >= base)
		ft_putnbr_base(num / base, base, charset, symb);
	write(1, &charset[num % base], 1);
	*symb = *symb + 1;
}

void	putnbr_abs(int num, int base, char *charset, size_t *symb)
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1, symb);
		ft_putnbr_base((long int) -1 * num, base, charset, symb);
	}
	else
		ft_putnbr_base((long int) num, base, charset, symb);
}
