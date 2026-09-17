/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:07:32 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/27 15:07:33 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_basics(char specifier, va_list list);
int		ft_putchar_ba(char c);
int		ft_puthex_ba(unsigned long nbr, char format);
void	ft_putnbr_ba(long nbr);
int		ft_putstr_ba(char *s);

#endif
