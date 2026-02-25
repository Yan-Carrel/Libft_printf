/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:20:06 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 15:59:11 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_putstr_ba(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}