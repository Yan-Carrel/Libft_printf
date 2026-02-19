/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:39:52 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/19 15:12:58 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft.h"

static void print_n_str(char *s, size_t len);
void    print_left(infos print_info, char *s);
void    print_right(infos print_info, char *s);
static  void print_caseA(infos print_info, char *s);
static void print_caseB(infos print_info, char *s);
static void print_caseC(infos print_info, char *s);
static int get_spaces_to_print(char *s, infos print_info, int print_len, int zeros);
void    print_nbr(infos print_info, char *s)
{
    if (!s)
        s = "(null)";
    if (print_info.justification == 'l')
        print_left(print_info, s);
    else
        print_right(print_info, s);
}

void    print_left(infos print_info, char *s)
{
    int print_len;
    int zeros_len;
    int spaces;

    print_len = get_print_len(s);
    zeros_len = get_zeros(print_info, print_len);
    spaces = get_spaces_to_print(s, print_info, print_len, zeros_len);

    if (s[0] == '-')
        ft_putchar_fd('-', 1);
    print_spaces('0', zeros_len);
    if (s[0] == '-')
        print_n_str(&s[1], print_len);
    else
        print_n_str(s, print_len);
    print_spaces(' ', spaces);
}

void    print_right(infos print_info, char *s)
{
    if(print_info.precision == 0 && s[0] == '0' && s[1] == '\0')
    {
        print_spaces(' ', print_info.width);
        return;
    }
    else if (print_info.precision >= 0)
        print_caseA(print_info, s);
    else if (print_info.precision == -1 && print_info.pad == '0')
        print_caseB(print_info, s);
    else if (print_info.precision < 0 && print_info.pad != '0')
        print_caseC(print_info, s);
}

static void print_caseA(infos print_info, char *s)
{
    int print_len;
    int zeros;
    int spaces;
    int neg;

    neg = (s[0] == '-');
    print_len = get_print_len(s);
    zeros = get_zeros(print_info, print_len);
    spaces = get_spaces_to_print(s, print_info, print_len, zeros);
    print_spaces(' ', spaces);
    if (neg)
        ft_putchar_fd('-', 1);
    print_spaces('0', zeros);
    if (!(print_info.precision == 0 && s[0] == '0' && s[1] == '\0'))
    {
        if (neg)
            print_n_str(&s[1], print_len);
        else
            print_n_str(s, print_len);
    }
}   

static void print_caseB(infos print_info, char *s)
{
    int print_len;
    int zeros;
    int spaces;
    int neg;

    spaces = 0;
    neg = (s[0] == '-');
    print_len = get_print_len(s);
    zeros = print_info.width - (print_len + neg);
    if (zeros < 0)
        zeros = 0;
    if (s[0] == '-')
        ft_putchar_fd('-', 1);
    print_spaces('0', zeros);
    if (neg)
        print_n_str(&s[1], print_len);
    else
        print_n_str(s, print_len);
}

static void print_caseC(infos print_info, char *s)
{
    int print_len;
    int zeros;
    int spaces;
    int neg;

    neg = (s[0] == '-');
    print_len = get_print_len(s);
    zeros = get_zeros(print_info, print_len);
    spaces = get_spaces_to_print(s, print_info, print_len, zeros);
    print_spaces(' ', spaces);
    if (neg)
        ft_putchar_fd('-', 1);
    if (neg)
        print_n_str(&s[1], print_len);
    else
        print_n_str(s, print_len);
}

static void print_n_str(char *s, size_t len)
{
    size_t i;

    i = 0;
    while (i < len)
    {
        ft_putchar_fd(s[i], 1);
        i++;
    }
}

static int get_spaces_to_print(char *s, infos print_info, int print_len, int zeros)
{
    int spaces;
    int neg;

    spaces = 0;
    neg = (s[0] == '-');
    if (print_info.width > (print_len + zeros))
    {
        spaces = print_info.width - (print_len + zeros);
        if (neg)
            spaces --;
        return (spaces);
    }
    return (0);
}