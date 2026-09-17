/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:39:59 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/27 16:26:42 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	count_digits(long n, char specifier);
int	get_zeros(t_infos print_info, int print_len);
int	spaces_to_print(t_infos print_info, int print_len, int zeros_len, int neg);

int	handle_signs(t_infos print_info, int neg)
{
	int	count;

	count = 0;
	if (neg)
		count++;
	if (print_info.plus == '+' && (print_info.specifier == 'd'
			|| print_info.specifier == 'i') && !neg)
		count++;
	return (count);
}

int	get_zeros(t_infos print_info, int print_len)
{
	if (print_info.precision > print_len)
		return (print_info.precision - print_len);
	return (0);
}

int	count_digits(long n, char specifier)
{
	int				count;
	unsigned long	nb;

	count = 0;
	if ((specifier == 'd' || specifier == 'i') && n < 0)
		nb = -n;
	else
		nb = (unsigned long)n;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	spaces_to_print(t_infos print_info, int print_len, int zeros_len, int neg)
{
	int	sign_len;
	int	total_len;

	sign_len = 0;
	if (neg || (print_info.plus == '+' && (print_info.specifier == 'd'
				|| print_info.specifier == 'i')))
		sign_len = 1;
	if (print_info.pad == '0' && print_info.precision < 0)
	{
		total_len = print_len + sign_len;
		if (print_info.width > total_len)
			return (print_info.width - total_len);
		return (0);
	}
	else
	{
		total_len = print_len + zeros_len + sign_len;
		if (print_info.width > total_len)
			return (print_info.width - total_len);
		return (0);
	}
}
