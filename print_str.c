/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:46:15 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/19 15:37:46 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_printf.h"

static void print_n_str(char *s, size_t len);
void    print_string(infos print_info, char *s)
{
    int str_print_len;

    if (!s)
        s = "(null)";
    str_print_len = ft_strlen(s);
    if (print_info.precision >= 0 && str_print_len > print_info.precision)
        str_print_len = print_info.precision;
    if (print_info.justification == 'l')
        print_n_str(s, str_print_len);
    print_spaces(print_info.pad, print_info.width - str_print_len);
    if (print_info.justification != 'l')
        print_n_str(s, str_print_len);
}

static void print_n_str(char *s, size_t len)
{
    size_t i;

    i = 0;
    while (i < len)
    {
        ft_putchar_fd(s[i] , 1);
        i++;
    }
}