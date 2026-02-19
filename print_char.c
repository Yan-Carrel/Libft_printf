/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:26:47 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/19 13:06:02 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft.h"

void    print_char(infos print_info, char c)
{
    if (!c)
        return ;
    if (print_info.precision == 0)
        print_spaces (print_info.width, print_info.width);
    if (print_info.precision > 0 && print_info.justification == 'l')
    {
        ft_putchar_fd (c, 1);
        print_spaces(print_info.pad, print_info.width - 1);
    }
    if (print_info.justification != 'l' && print_info.precision > 0)
    {
        print_spaces(print_info.pad, print_info.width - 1);
        ft_putchar_fd(c, 1);
    }
}