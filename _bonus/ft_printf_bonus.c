/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:01:11 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/24 16:53:10 by yaandria         ###   ########.fr       */
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

int main(void)
{
    
    // ft_printf("|%5.3d|", 42);
    // ft_printf("|%010.2s|", "hello");

    int len1;
    int len2;

    // Test 1: simple string
    len1 = printf("Hello World\n");
    len2 = ft_printf("Hello World\n");
    printf("printf: %d, ft_printf: %d\n", len1, len2);

    // Test 2: string with NULL
    // len1 = printf("NULL string: %s\n", (char *)NULL);
    // len2 = ft_printf("NULL string: %s\n", (char *)NULL);
    // printf("\nprintf: %d, ft_printf: %d\n", len1, len2);

    // Test 3: characters
    // len1 = printf("Chars: %c %c %c\n", 'a', 'Z', '0');
    // len2 = ft_printf("Chars: %c %c %c\n", 'a', 'Z', '0');
    // printf("printf: %d, ft_printf: %d\n", len1, len2);

    // // Test 4: integers
    len1 = printf("Numbers: %+-010.5d %+-010.5i %+-010.5u\n", 42, -42, 3000000000u);
    len2 = ft_printf("Numbers: %+-010.5d %+-010.5i %+-010.5u\n", 42, -42, 3000000000u);
    printf("printf: %d, ft_printf: %d\n", len1, len2);

    // // Test 5: hex
    // ft_printf("hex with # flag\n");
    // len1 = printf("Hex: %#x %#X\n", 255, 255);
    // len2 = ft_printf("Hex: %#x %#X\n", 255, 255);
    // printf("printf: %d, ft_printf: %d\n", len1, len2);

    // // Test 6: pointer
    // int a;
    // len1 = printf("Pointer: %p\n", &a);
    // len2 = ft_printf("Pointer: %p\n", &a);
    // printf("printf: %d, ft_printf: %d\n", len1, len2);

    // // Test 7: mix everything
    // len1 = printf("Mix: %s %c %d %x %p\n", "str", 'B', -123, 0xabc, &a);
    // len2 = ft_printf("Mix: %s %c %d %x %p\n", "str", 'B', -123, 0xabc, &a);
    // printf("printf: %d, ft_printf: %d\n", len1, len2);

    return 0;
}