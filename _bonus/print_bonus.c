/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:51:49 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/27 16:08:50 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	handle_digits(va_list list, t_infos print_info);
static int	handle_pointer(va_list list, t_infos print_info);

int	print(t_infos print_info, va_list list)
{
	char	c;
	char	*s;

	c = '\0';
	if (print_info.specifier == 'c')
	{
		c = va_arg(list, int);
		return (print_char(print_info, c));
	}
	else if (print_info.specifier == 'x' || print_info.specifier == 'X')
		return (print_hex(print_info, va_arg(list, unsigned int)));
	else if (print_info.specifier == 'd' || print_info.specifier == 'i'
		|| print_info.specifier == 'u')
		return (handle_digits(list, print_info));
	if (print_info.specifier == 'p')
		return (handle_pointer(list, print_info));
	else
	{
		s = va_arg(list, char *);
		if (!s)
			return (print_string(print_info, "(null)"));
		return (print_string(print_info, s));
	}
	return (0);
}

static int	handle_digits(va_list list, t_infos print_info)
{
	if (print_info.specifier == 'd' || print_info.specifier == 'i')
		return (print_nbr(print_info, va_arg(list, int)));
	else
		return (print_nbr(print_info, va_arg(list, unsigned int)));
}

static int	handle_pointer(va_list list, t_infos print_info)
{
	void	*ptr;

	ptr = va_arg(list, void *);
	if (ptr == NULL)
		return (print_string(print_info, "(nil)"));
	else
		return (print_pointer(print_info, (unsigned long)ptr));
}
