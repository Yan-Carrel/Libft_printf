#ifndef LIBFT_PRINTF_H
#define LIBFT_PRINTF_H

#include <stdarg.h>
#include "libft.h"
#include "libft_printf.h"

typedef struct informations
{
    int width;
    int precision;
    char justification;
    char pad;
    char specifier;
}infos;
void    parse_all(char *first, infos *print_info, int *i_ptr);
void    format_and_print(infos info, va_list list);
void    print_string(infos print_info, char *s);
void    print_char(infos print_info, char c);
void    print_nbr(infos print_info, char *s);
int     get_print_len(char *s);
int     get_zeros(infos print_info, int print_len);
int     spaces_to_print(char *s, infos print_info, int print_len, int zeros_len);
void    print_spaces(char c, int n);
int spaces_to_print(char *s, infos print_info, int print_len, int zeros_len);
char *convert_hex(int nbr);

#endif