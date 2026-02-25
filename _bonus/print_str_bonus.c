/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:15 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:58:42 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_n_str(char *s, size_t len);
static void	print_spaces(infos print_info, int n);
int	print_string(infos print_info, char *s)
{
	int	str_print_len;

	str_print_len = ft_strlen(s);
	if (print_info.precision >= 0 && str_print_len > print_info.precision)
		str_print_len = print_info.precision;
	if (print_info.justification == 'l')
		print_n_str(s, str_print_len);
	print_spaces(print_info, print_info.width - str_print_len);
	if (print_info.justification != 'l')
		print_n_str(s, str_print_len);
	if (str_print_len > print_info.width)
		return (str_print_len);
	return (print_info.width);
}

static void	print_n_str(char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

static void	print_spaces(infos print_info, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(print_info.pad, 1);
		i++;
	}
}