/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:02:00 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/19 13:13:45 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft.h"

int spaces_to_print(char *s, infos print_info, int print_len, int zeros_len);
void    print_spaces(char c, int n);
int get_print_len(char *s);
int get_zeros(infos print_info, int print_len)
{
    if (print_info.precision > print_len)
        return (print_info.precision - print_len);
    return (0);
}

int spaces_to_print(char *s, infos print_info, int print_len, int zeros_len)
{
    if (s[0] == '-')
        print_len++;
    if (print_info.width > zeros_len + print_len)
            return (print_info.width - (zeros_len + print_len));
    return (0);
}

void    print_spaces(char c, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        ft_putchar_fd(c, 1);
        i++;
    }
}

int get_print_len(char *s)
{
    if (s[0] == '-')
        return (ft_strlen(s) - 1);
    else
        return (ft_strlen(s));
}