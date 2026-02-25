/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:18:06 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:59:24 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list			list;
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		else
		{
			count += print_basics(format[i + 1], list);
			i++;
		}
		i++;
	}
	va_end(list);
	return (count);
}
