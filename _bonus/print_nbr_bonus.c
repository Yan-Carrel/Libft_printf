/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:39:52 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:28:55 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_nbr_spaces(char c, int len);
static int	handle_signs(infos print_info, int neg);
static int	count_digits(long n, char specifier);
static void	print_signs(infos print_info, int neg);
static int	spaces_to_print(infos print_info, int print_len, int zeros_len,
				int neg);
static int	get_zeros(infos print_info, int print_len);
static int	print_left(infos print_info, long nbr, int zeros, int print_len);
static int	print_right(infos print_info, long nbr, int zeros, int print_len);
int	print_nbr(infos print_info, long nbr)
{
	int	print_len;
	int	zeros;
	int	count;

	count = 0;
	zeros = 0;
	if (print_info.precision == 0 && nbr == 0)
		print_len = 0;
	else
		print_len = count_digits(nbr, print_info.specifier);
	zeros = get_zeros(print_info, print_len);
	if (print_info.justification == 'l')
		return (print_left(print_info, nbr, zeros, print_len));
	else
		return (print_right(print_info, nbr, zeros, print_len));
	return (count);
}

static int	print_left(infos print_info, long nbr, int zeros, int print_len)
{
	int	spaces;
	int	neg;
	int	sign_count;

	neg = (nbr < 0);
	if (neg)
		nbr *= -1;
	spaces = spaces_to_print(print_info, print_len, zeros, neg);
	sign_count = handle_signs(print_info, neg);
	print_signs(print_info, neg);
	print_nbr_spaces('0', zeros);
	ft_put_n_nbr(nbr, print_len);
	print_nbr_spaces(' ', spaces);
	return (spaces + zeros + print_len + sign_count);
}

static int	print_right(infos print_info, long nbr, int zeros, int print_len)
{
	int	spaces;
	int	neg;
	int	sign_count;

	neg = (nbr < 0);
	if (neg)
		nbr *= -1;
	spaces = spaces_to_print(print_info, print_len, zeros, neg);
	sign_count = handle_signs(print_info, neg);
	if (print_info.pad == '0' && print_info.precision < 0)
	{
		sign_count = handle_signs(print_info, neg);
		print_signs(print_info, neg);
		print_nbr_spaces('0', spaces + zeros);
		ft_put_n_nbr(nbr, print_len);
	}
	else
	{
		print_nbr_spaces(' ', spaces);
		print_signs(print_info, neg);
		print_nbr_spaces('0', zeros);
		ft_put_n_nbr(nbr, print_len);
	}
	return (print_len + zeros + spaces + neg + sign_count);
}

static int	handle_signs(infos print_info, int neg)
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

static void	print_signs(infos print_info, int neg)
{
	if (neg)
		ft_putchar_fd('-', 1);
	else if (print_info.plus == '+' && (print_info.specifier == 'd'
			|| print_info.specifier == 'i'))
		ft_putchar_fd('+', 1);
}

static void	print_nbr_spaces(char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}

static int	count_digits(long n, char specifier)
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

static int	get_zeros(infos print_info, int print_len)
{
	if (print_info.precision > print_len)
		return (print_info.precision - print_len);
	return (0);
}

static int	spaces_to_print(infos print_info, int print_len, int zeros_len,
		int neg)
{
	int	sign_len;

	sign_len = (neg || (print_info.plus == '+' && (print_info.specifier == 'd'
					|| print_info.specifier == 'i'))) ? 1 : 0;
	if (print_info.pad == '0' && print_info.precision < 0)
	{
		return ((print_info.width > (print_len + sign_len)) ? print_info.width
			- (print_len + sign_len) : 0);
	}
	else
	{
		return ((print_info.width > (print_len + zeros_len
					+ sign_len)) ? print_info.width - (print_len + zeros_len
				+ sign_len) : 0);
	}
}
