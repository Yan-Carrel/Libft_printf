/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_n_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:47:22 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:58:19 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	count_digits(long n);
void	ft_put_n_nbr(long nbr, int n)
{
	int	count;

	count = count_digits(nbr);
	if (n <= 0)
		return ;
	while (count > n)
	{
		nbr /= 10;
		count--;
	}
	if (n > 1)
		ft_put_n_nbr(nbr, n - 1);
	ft_putchar_fd((nbr % 10) + '0', 1);
}

static int	count_digits(long n)
{
	int count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}