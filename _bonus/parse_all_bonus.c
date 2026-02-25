/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:57:32 by yaandria          #+#    #+#             */
/*   Updated: 2026/02/24 14:16:36 by yaandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void parse_pad(infos *print_info, const char *first, int *i_ptr);
static void parse_width(infos *print_info, const char *first, int *i_ptr);
static void parse_precision(infos *print_info, const char *first, int *i_ptr);
void    parse_all(const char *first, infos *print_info, int *i_ptr)
{
    (*i_ptr)++;
    print_info->pad = ' ';
    print_info->width = 0;
    print_info->precision = -1;
    print_info->specifier = '\0';
    print_info->justification = 'r';
    print_info->hash = '0';
    print_info->plus = '0';
    parse_pad(print_info, first, i_ptr);
    parse_width(print_info, first, i_ptr);
    parse_precision(print_info, first, i_ptr);
    if (first[*i_ptr])
        print_info->specifier = first[*i_ptr];
}

static void parse_pad(infos *print_info, const char *first, int *i_ptr)
{
    while (first[*i_ptr] != '.' 
        && !(first[*i_ptr] >= '1' && first[*i_ptr] <= '9') 
        && !(first[*i_ptr] >= 'c' && first[*i_ptr] <= 'x') 
        && first[*i_ptr] != 'X')
    {
        if (first[*i_ptr] == '+')
            print_info->plus = '+';
        if (first[*i_ptr] == '#')
            print_info->hash = '#';
        if (first[*i_ptr] == '-')
            print_info->justification = 'l';
        if (first[*i_ptr] == '0')
            print_info->pad = '0';
        (*i_ptr)++;
    }
}

static void parse_width(infos *print_info, const char *first, int *i_ptr)
{
    if (first[*i_ptr] >= '1' && first[*i_ptr] <= '9')
    {
        print_info->width += (first[*i_ptr] - '0');
        (*i_ptr)++;
    }
    while (first[*i_ptr] >= '0' && first[*i_ptr] <= '9')
    {    
        print_info->width = print_info->width * 10 + (first[*i_ptr] - '0');
        (*i_ptr)++;
    }
}

static void parse_precision(infos *print_info, const char *first, int *i_ptr)
{
    if (first[*i_ptr] == '.')
        (*i_ptr)++;
    if (first[*i_ptr] >= '0' && first[*i_ptr] <= '9')
        print_info->precision = 0;
    while (first[*i_ptr] >= '0' && first[*i_ptr] <= '9')
    {    
        print_info->precision = print_info->precision * 10 + (first[*i_ptr] - '0');
        (*i_ptr)++;
    }
}