/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 07:28:30 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/11 13:21:06 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_string(char *number, int n, int len);
static int	get_len(int n);

char	*ft_itoa(int n)
{
	char	*number;
	int		len;
	int		initial_n_value;

	initial_n_value = n;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (ft_strdup("-2147483648"));
		n *= -1;
	}
	len = get_len(initial_n_value);
	number = malloc((len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	if (initial_n_value < 0)
		number[0] = '-';
	fill_string(number, initial_n_value, len);
	return (number);
}

static int	get_len(int initial_n_value)
{
	int	len;

	len = 0;
	if (initial_n_value <= 0)
	{
		len++;
		initial_n_value *= -1;
	}
	while (initial_n_value != 0)
	{
		initial_n_value /= 10;
		len++;
	}
	return (len);
}

static void	fill_string(char *number, int n, int len)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	number[len] = '\0';
	len--;
	while (len != 0)
	{
		if (n > 9)
			number[len] = (n % 10) + '0';
		else
			number[len] = n + '0';
		n /= 10;
		len--;
	}
	if (sign >= 0)
		number[len] = n + '0';
}
