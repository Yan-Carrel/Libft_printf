/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:09:52 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/24 13:50:09 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_puthex(unsigned long nbr, char format)
{
	char			*base;
	int				count;
	unsigned long	nbr_cpy;

	count = 0;
	nbr_cpy = nbr;
	while (nbr_cpy >= 16)
	{
		nbr_cpy /= 16;
		count++;
	}
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		ft_puthex(nbr / 16, format);
	ft_putchar_fd(base[nbr % 16], 1);
	return (count + 1);
}
