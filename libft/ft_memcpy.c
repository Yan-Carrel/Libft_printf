/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:18:10 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/27 14:28:43 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

int	main(void)
{
	char	src[6];
	char	dest[6];
	size_t	i;

	src[0] = 'H';
	src[1] = 'e';
	src[2] = 'l';
	src[3] = 'l';
	src[4] = 'o';
	src[5] = '\0';
	ft_memcpy(dest, src, 6);
	i = 0;
	while (i < 6)
	{
		ft_putchar_fd(dest[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	return (0);
}
