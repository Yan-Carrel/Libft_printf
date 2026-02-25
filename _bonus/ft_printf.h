/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:05:21 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:56:57 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct informations
{
	int		width;
	int		precision;
	char	justification;
	char	pad;
	char	specifier;
	char	hash;
	char	plus;
}			infos;
int			ft_printf(const char *format, ...);
void		parse_all(const char *first, infos *print_info, int *i_ptr);
int			print(infos info, va_list list);
int			print_string(infos print_info, char *s);
int			print_char(infos print_info, char c);
int			print_nbr(infos print_info, long nbr);
int			print_hex(infos print_info, unsigned int nbr);
int			ft_puthex(unsigned long nbr, char format);
void		ft_put_n_nbr(long nbr, int n);
int			print_pointer(infos print_info, unsigned long nbr);

#endif
