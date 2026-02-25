/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:34:30 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/24 12:17:50 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

static int count_digits (long n);
static int  handle_str(va_list list);
static int  handle_pointer(va_list list, char specifier);
static int  handle_digits(va_list list, char specifier);
int print_basics(char specifier, va_list list)
{
    if (specifier == 'c')
        return (ft_putchar_ba(va_arg(list, int)));
    else if (specifier == 's')
        return (handle_str(list));
    else if (specifier == 'p')
        return (handle_pointer(list, specifier));
    else if (specifier == 'd' || specifier == 'i' || specifier == 'u')
        return (handle_digits(list, specifier));
    else if (specifier == 'x' || specifier == 'X')
        return (ft_puthex_ba(va_arg(list, unsigned int), specifier));
    else
    {
        ft_putchar_fd('%', 1);
        return (1);
    }
}

static int  handle_str(va_list list)
{
    char *str;
    
    str = va_arg(list, char *);
    if (str == NULL)
        return(ft_putstr_ba ("(null)"));
    else
        return (ft_putstr_ba(str));
}

static int  handle_pointer(va_list list, char specifier)
{
    void *ptr;

    ptr = va_arg(list, void *);
    if (ptr == NULL)
        return (ft_putstr_ba("(nil)"));
    else
    {
        ft_putstr_fd("0x", 1);
        return (ft_puthex_ba((unsigned long)ptr, specifier) + 2);
    }
}

static int  handle_digits(va_list list, char specifier)
{
    long nbr;
    
    if (specifier == 'd' || specifier == 'i')
            nbr = va_arg(list, int);
    else
        nbr = va_arg(list, unsigned int);
    ft_putnbr_ba(nbr);
    return (count_digits(nbr));
}

static int count_digits(long n)
{
    int count;

    count = 1;
    if (n < 0)
    {
        n *= -1;
        count ++;
    }
    while (n > 9)
    {
        n /= 10;
        count++;
    }
    return (count);
}
