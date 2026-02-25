#include "libft_printf.h"
#include "libft.h"

#include <stdio.h>

char *convert_hex(int nbr)
{
    return ((nbr % 16) - 10 + 'a');
}

int main(void)
{
    printf("%x", convert_hex(348));
}