/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:30:32 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:59:05 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_putnbr_ba(long nbr)
{
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', 1);
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', 1);
	if (nbr > 9)
	{
		ft_putnbr_ba(nbr / 10);
		ft_putnbr_ba(nbr % 10);
	}
}
