/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:01:11 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/25 14:43:49 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int process(const char *first, va_list list, int *i);
int    ft_printf(const char *first, ...)
{
    va_list list;
    int i;
    unsigned int count;

    i = 0;
    count = 0;
    va_start(list, first);
    while (first[i] != '\0')
    {
        if (first[i] != '%')
        {
            ft_putchar_fd(first[i], 1);
            count++;
        }
        else
            count += process(first, list, &i);
        i++;
    }
    va_end(list);
    return (count);
}

static int process(const char *first, va_list list, int *i)
{
    infos   print_info;
    unsigned int count;

    count = 0;
    if (first[*i + 1] == '%')
    {
        ft_putchar_fd('%', 1);
        count ++;
        (*i)++;
        return (count);
    }
    else
    {
        parse_all(first, &print_info, i);
        count +=print(print_info, list);
    }
    return (count);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int len1;
    int len2;
    int a = 42;
    int neg = -42;
    unsigned int u = 3000000000u;

    printf("=========== BASIC TESTS ===========\n\n");

    // 1. Simple characters
    len1 = printf("T1 |%c|\n", 'A');
    len2 = ft_printf("T1 |%c|\n", 'A');
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    // 2. String normal
    len1 = printf("T2 |%s|\n", "Hello");
    len2 = ft_printf("T2 |%s|\n", "Hello");
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    // 3. String NULL
    len1 = printf("T3 |%s|\n", (char *)NULL);
    len2 = ft_printf("T3 |%s|\n", (char *)NULL);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== WIDTH & PRECISION ===========\n\n");

    // 4. Width
    len1 = printf("T4 |%10d|\n", a);
    len2 = ft_printf("T4 |%10d|\n", a);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    // 5. Precision
    len1 = printf("T5 |%.5d|\n", a);
    len2 = ft_printf("T5 |%.5d|\n", a);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    // 6. Width + Precision
    len1 = printf("T6 |%10.5d|\n", a);
    len2 = ft_printf("T6 |%10.5d|\n", a);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== FLAG '-' (LEFT ALIGN) ===========\n\n");

    len1 = printf("T7 |%-10d|\n", a);
    len2 = ft_printf("T7 |%-10d|\n", a);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    len1 = printf("T8 |%-10s|\n", "Hi");
    len2 = ft_printf("T8 |%-10s|\n", "Hi");
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== FLAG '0' ===========\n\n");

    len1 = printf("T9 |%010d|\n", a);
    len2 = ft_printf("T9 |%010d|\n", a);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    len1 = printf("T10 |%010i|\n", neg);
    len2 = ft_printf("T10 |%010i|\n", neg);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== FLAG '+' ===========\n\n");

    len1 = printf("T11 |%+d|\n", a);
    len2 = ft_printf("T11 |%+d|\n", a);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    len1 = printf("T12 |%+d|\n", neg);
    len2 = ft_printf("T12 |%+d|\n", neg);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== FLAG '#' ===========\n\n");

    len1 = printf("T13 |%#x|\n", 255);
    len2 = ft_printf("T13 |%#x|\n", 255);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    len1 = printf("T14 |%#X|\n", 255);
    len2 = ft_printf("T14 |%#X|\n", 255);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== UNSIGNED ===========\n\n");

    len1 = printf("T15 |%u|\n", u);
    len2 = ft_printf("T15 |%u|\n", u);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    len1 = printf("T16 |%10.8u|\n", u);
    len2 = ft_printf("T16 |%10.8u|\n", u);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== HEXA COMPLEX ===========\n\n");

    len1 = printf("T17 |%#08x|\n", 42);
    len2 = ft_printf("T17 |%#08x|\n", 42);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    len1 = printf("T18 |%-#10.5X|\n", 42);
    len2 = ft_printf("T18 |%-#10.5X|\n", 42);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== POINTER ===========\n\n");

    len1 = printf("T19 |%p|\n", &a);
    len2 = ft_printf("T19 |%p|\n", &a);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    len1 = printf("T20 |%20p|\n", &a);
    len2 = ft_printf("T20 |%20p|\n", &a);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== EDGE CASES ===========\n\n");

    // precision = 0 and value = 0
    len1 = printf("T21 |%.0d|\n", 0);
    len2 = ft_printf("T21 |%.0d|\n", 0);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    len1 = printf("T22 |%.0x|\n", 0);
    len2 = ft_printf("T22 |%.0x|\n", 0);
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    printf("=========== MIXED CRAZY TEST ===========\n\n");

    len1 = printf("T23 |%-+10.5d| |%#08x| |%-10s| |%c|\n", -123, 48879, "Test", 'Z');
    len2 = ft_printf("T23 |%-+10.5d| |%#08x| |%-10s| |%c|\n", -123, 48879, "Test", 'Z');
    printf("printf: %d, ft_printf: %d\n\n", len1, len2);

    return 0;
}