/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:22:10 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/27 13:49:40 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_puthex_ba(unsigned long nbr, char format)
{
	char			*base;
	int				count;
	unsigned long	nbr_cpy;

	count = 1;
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
		ft_puthex_ba(nbr / 16, format);
	ft_putchar_fd(base[nbr % 16], 1);
	return (count);
}
