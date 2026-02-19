/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_and_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:51:49 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/19 16:16:34 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft.h"

static char *extract_argument(char c, va_list list);
void    format_and_print(infos print_info, va_list list)
{
    char c;
    char *s;

    s = NULL;
    c = '\0';
    if (print_info.specifier == 'c')
        c = va_arg(list, int);
    else
        s = extract_argument(print_info.specifier, list);
    if (c != '\0')
        print_char(print_info, c);
    else if (s != NULL)
    {
        if (print_info.specifier == 'd' || print_info.specifier == 'i')
            print_nbr(print_info, s);
        else
            print_string(print_info, s);
    }
}

static char *extract_argument(char c, va_list list)
{
    if (c == 's')
        return (va_arg(list, char *));
    return (ft_itoa(va_arg(list, int)));
    // if (c == 'p')
    //     return (convert_hexadecimal(va_arg(list, int)));
    if (c == 'u')
        return (ft_itoa(va_arg(list, unsigned int)));
    if (c == 'x' || c == 'X')
        return (convert_hex(va_arg(list, int)));
    return (NULL);
}