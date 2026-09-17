/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:02:09 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/11 14:30:42 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	strlen_s1;
	size_t	strlen_s2;

	if (!s1 || !s2)
		return (NULL);
	strlen_s1 = ft_strlen(s1);
	strlen_s2 = ft_strlen(s2);
	buffer = malloc(strlen_s1 + strlen_s2 + 1);
	if (!buffer)
		return (NULL);
	buffer[strlen_s1 + strlen_s2] = '\0';
	ft_memcpy(buffer, s1, ft_strlen(s1));
	ft_memcpy(&buffer[strlen_s1], s2, strlen_s2);
	return (buffer);
}
