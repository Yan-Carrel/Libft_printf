/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:09:46 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 14:02:15 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	put_padding(char c, int len);
static int	hex_len(unsigned long n);
void    print_caseA(unsigned long nbr, int precision_zeros, int digits_len, int padding);
void    print_caseB(unsigned long nbr, int digits_len, int padding);
void   print_caseC(unsigned long nbr, int precision_zeros, int digits_len, int padding);
int	print_pointer(infos info, unsigned long nbr)
{
	int	digits_len;
	int	precision_zeros;
	int	total_len;
	int	padding;

	digits_len = 0;
    precision_zeros = 0;
	if (!(nbr == 0 && info.precision == 0))
		digits_len = hex_len(nbr);
	if (info.precision > digits_len)
		precision_zeros = info.precision - digits_len;
	total_len = 2 + digits_len + precision_zeros;
	if (info.width > total_len)
		padding = info.width - total_len;
	else
		padding = 0;
	if (info.justification == 'l')
		print_caseA(nbr, precision_zeros, digits_len, padding);
	else if (info.pad == '0' && info.precision == -1)
        print_caseB(nbr, digits_len, padding);
	else
        print_caseC(nbr, precision_zeros, digits_len, padding);
	if (info.width > total_len)
		return (info.width);
	return (total_len);
}

void    print_caseA(unsigned long nbr, int precision_zeros, int digits_len, int padding)
{
    ft_putstr_fd("0x", 1);
    put_padding('0', precision_zeros);
    if (digits_len > 0)
        ft_puthex(nbr, 'x');
    put_padding(' ', padding);
}

void    print_caseB(unsigned long nbr, int digits_len, int padding)
{
    ft_putstr_fd("0x", 1);
    put_padding('0', padding);
    if (digits_len > 0)
    ft_puthex(nbr, 'x');
}

void   print_caseC(unsigned long nbr, int precision_zeros, int digits_len, int padding)
{
    put_padding(' ', padding);
    ft_putstr_fd("0x", 1);
    put_padding('0', precision_zeros);
    if (digits_len > 0)
        ft_puthex(nbr, 'x');
}

static void	put_padding(char c, int len)
{
	while (len-- > 0)
		ft_putchar_fd(c, 1);
}

static int	hex_len(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}
