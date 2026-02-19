/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:01:11 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/19 16:15:53 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft.h"

int    ft_printf(char *first, ...)
{
    va_list list;
    infos print_info;
    int i;

    i = 0;
    va_start(list, first);
    while (first[i] != '\0')
    {
        if (first[i] != '%')
            ft_putchar_fd(first[i], 1);
        else
        {
            parse_all(first, &print_info, &i);
            format_and_print(print_info, list);
        }
        i++;
    }
    va_end(list);
    return (i);
}

// #include <stdio.h>

// int main(void)
// {
//     unsigned int nbr = 255;

//     ft_printf("TEST x: %x\n", nbr);
//     printf("REAL   : %x\n\n", nbr);


// }