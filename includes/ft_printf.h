/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:07:32 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/24 11:18:31 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FT_PRINT_F_H)
# define FT_PRINT_F_H

# include "../includes/ft_printf.h"
# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_basics(char specifier, va_list list);
int		ft_putchar_ba(char c);
int		ft_puthex_ba(unsigned long nbr, char format);
void	ft_putnbr_ba(long nbr);
int     ft_putstr_ba(char *s);

#endif
