/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:01:11 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:58:11 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	process(const char *first, va_list list, int *i);
int	ft_printf(const char *first, ...)
{
	va_list			list;
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	va_start(list, first);
	while (first[i] != '\0')
	{
		if (first[i] != '%')
		{
			ft_putchar_fd(first[i], 1);
			count++;
		}
		else
			count += process(first, list, &i);
		i++;
	}
	va_end(list);
	return (count);
}

static int	process(const char *first, va_list list, int *i)
{
	infos			print_info;
	unsigned int	count;

	count = 0;
	if (first[*i + 1] == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
		(*i)++;
		return (count);
	}
	else
	{
		parse_all(first, &print_info, i);
		count += print(print_info, list);
	}
	return (count);
}
