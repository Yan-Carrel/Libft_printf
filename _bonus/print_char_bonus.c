/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:26:47 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/23 14:03:41 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void print_spaces(infos print_info, int n);
int    print_char(infos print_info, char c)
{
    int padding;

    padding = 0;
    if (print_info.width > 1)
        padding = print_info.width - 1;
    if (print_info.justification == 'l')
    {
        ft_putchar_fd (c, 1);
        print_spaces(print_info, padding);
    }
    else
    {
            print_spaces(print_info, padding);
            ft_putchar_fd (c, 1);
    }
    if (print_info.width > 1)
        return (print_info.width);
    return (1);
}

static void print_spaces(infos print_info, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        ft_putchar_fd(print_info.pad , 1);
        i++;
    }
}