/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:02:00 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:58:33 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_n_characters(int len, char c);
static int	count_len(unsigned long nbr);
static void	print_characters(infos print_info, long nbr, int spaces, int zeros);
int	print_hex(infos print_info, unsigned int nbr)
{
	int	print_len;
	int	hex_len;
	int	zeros;
	int	spaces;

	if (nbr == 0 && print_info.precision == 0)
		hex_len = 0;
	else
		hex_len = count_len(nbr);
	print_len = hex_len;
	if (print_info.hash == '#' && nbr != 0)
		print_len += 2;
	zeros = 0;
	if (print_info.precision > hex_len)
		zeros = print_info.precision - hex_len;
	spaces = 0;
	if (print_info.width > print_len + zeros)
		spaces = print_info.width - (print_len + zeros);
	print_characters(print_info, nbr, spaces, zeros);
	print_len = print_len + zeros;
	return (print_len + spaces);
}

static void	print_characters(infos print_info, long nbr, int spaces, int zeros)
{
	if (print_info.justification != 'l')
	{
		if (print_info.pad == '0' && print_info.precision < 0)
			print_n_characters(spaces, '0');
		else
			print_n_characters(spaces, ' ');
	}
	if (nbr != 0)
	{
		if (print_info.hash == '#' && nbr != 0)
		{
			if (print_info.specifier == 'x')
				ft_putstr_fd("0x", 1);
			else
				ft_putstr_fd("0X", 1);
		}
	}
	print_n_characters(zeros, '0');
	ft_puthex(nbr, print_info.specifier);
	if (print_info.justification == 'l')
		print_n_characters(spaces, ' ');
}

static void	print_n_characters(int len, char c)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}

static int	count_len(unsigned long nbr)
{
	int count;

	count = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}