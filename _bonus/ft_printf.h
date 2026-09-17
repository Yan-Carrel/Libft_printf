/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:05:21 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/27 16:27:49 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct informations
{
	int		width;
	int		precision;
	char	justification;
	char	pad;
	char	specifier;
	char	hash;
	char	plus;
}			t_infos;
int			ft_printf(const char *format, ...);
void		parse_all(const char *first, t_infos *print_info, int *i_ptr);
int			print(t_infos info, va_list list);
int			print_string(t_infos print_info, char *s);
int			print_char(t_infos print_info, char c);
int			print_nbr(t_infos print_info, long nbr);
int			print_hex(t_infos print_info, unsigned int nbr);
int			ft_puthex(unsigned long nbr, char format);
void		ft_put_n_nbr(long nbr, int n);
int			print_pointer(t_infos print_info, unsigned long nbr);
int			handle_signs(t_infos print_info, int neg);
int			get_zeros(t_infos print_info, int print_len);
int			spaces_to_print(t_infos print_info, int print_len, int zeros_len,
				int neg);
int			hex_len(unsigned long n);
void		put_padding(char c, int len);
int			count_digits(long n, char specifier);

#endif
