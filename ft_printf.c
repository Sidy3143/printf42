/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:45:50 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/14 15:45:51 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_printf(const char *s, ...)
{
    int i;
    int taille;
    va_list args;

    va_start(args, s);
    i = 0;
    taille = 0;
    while (s[i])
    {
        if (s[i] != '%')
        {
            write(1, &s[i], 1);
            taille++;
        }
        else
        {
            i++;
            if (s[i] == 'c')
                ft_printf_char();
            else if (s[i] == 's')
                ft_printf_str();
            else if (s[i] == 'i' || s[i] == 'd')
                ft_printf_int();
            else if (s[i] == 'p')
                ft_printf_adress();
            else if (s[i] == 'x')
                ft_printf_hex();
            else if (s[i] == 'X')
                ft_printf_hex(); // base 0123456789ABCDEF
        }
        i++;
    }
}