/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:58:07 by gajayme           #+#    #+#             */
/*   Updated: 2021/11/10 18:06:37 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putstr_fd(char *s, int fd, size_t *symb);
void	ft_putchar_fd(char c, int fd, size_t *symb);
void	putnbr_abs(int num, int base, char *charset, size_t *symb);
void	ft_putnbr_base(long int num, int base, char *charset, size_t *symb);
void	ft_putnbr_base_p(unsigned long int num, unsigned int base,
			 char *charset, size_t *symb);

#endif
