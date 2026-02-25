/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:18:06 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/24 12:05:54 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft.h"

int    ft_printf(const char *format, ...)
{
    va_list list;
    int i;
    unsigned int count;

    i = 0;
    count = 0;
    va_start(list, format);
    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            ft_putchar_fd(format[i], 1);
            count++;
        }
        else
        {
            count += print_basics(format[i + 1], list);
            i++;
        }
        i++;
    }
    va_end(list);
    return (count);
}

#include <stdio.h>
#include <limits.h>
#include <stdint.h>

// change this include to your header
int ft_printf(const char *format, ...);

void separator(void)
{
    printf("\n----------------------------------------\n");
}

// int main(void)
// {
//     int ret1;
//     int ret2;

//     separator();
//     printf("TEST: Basic string\n");
//     ret1 = printf("Hello %s\n", "World");
//     ret2 = ft_printf("Hello %s\n", "World");
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: Characters\n");
//     ret1 = printf("%c %c %c\n", 'A', 'B', 'C');
//     ret2 = ft_printf("%c %c %c\n", 'A', 'B', 'C');
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: Signed integers\n");
//     ret1 = printf("%d %i\n", 42, -42);
//     ret2 = ft_printf("%d %i\n", 42, -42);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: INT limits\n");
//     ret1 = printf("%d %d\n", INT_MAX, INT_MIN);
//     ret2 = ft_printf("%d %d\n", INT_MAX, INT_MIN);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: Unsigned\n");
//     ret1 = printf("%u\n", 4294967295u);
//     ret2 = ft_printf("%u\n", 4294967295u);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: Hex lowercase\n");
//     ret1 = printf("%x\n", 305441741);
//     ret2 = ft_printf("%x\n", 305441741);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: Hex uppercase\n");
//     ret1 = printf("%X\n", 305441741);
//     ret2 = ft_printf("%X\n", 305441741);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: Pointer\n");
//     int x = 42;
//     ret1 = printf("%p\n", &x);
//     ret2 = ft_printf("%p\n", &x);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: NULL string\n");
//     ret1 = printf("%s\n", NULL);
//     ret2 = ft_printf("%s\n", NULL);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: NULL pointer\n");
//     ret1 = printf("%p\n", NULL);
//     ret2 = ft_printf("%p\n", NULL);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: Percent\n");
//     ret1 = printf("100%% done\n");
//     ret2 = ft_printf("100%% done\n");
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     printf("TEST: Mixed\n");
//     ret1 = printf("Char:%c Str:%s Int:%d Hex:%x Ptr:%p %%\n",
//                   'Z', "test", -123, 255, &x);
//     ret2 = ft_printf("Char:%c Str:%s Int:%d Hex:%x Ptr:%p %%\n",
//                      'Z', "test", -123, 255, &x);
//     printf("printf len = %d | ft_printf len = %d\n", ret1, ret2);

//     separator();
//     return 0;
// }