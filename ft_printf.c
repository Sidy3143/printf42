/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:45:50 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/16 11:57:07 by sindiaye         ###   ########.fr       */
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
            {
                char c = va_arg(args, char);
                taille += ft_printf_char(c);
            }
            else if (s[i] == 's')
            {
                char    *str = va_arg(args, char *);
                taille += ft_printf_str(str);
            }
            else if (s[i] == 'i' || s[i] == 'd')
            {
                int n = va_arg(args, int);
                taille += ft_printf_int(n);
            }
            else if (s[i] == 'p')
            {
                void    *ptr = va_arg(args, void *);
                uintptr_t   adress = (uintptr_t)ptr;
                taille += ft_printf_hex(adress, "0123456789abcedf");
            }
            else if (s[i] == 'x')
            {
                unsigned int    n = va_arg(args, unsigned int);
                taille += ft_printf_hex(n, "0123456789abcdef");
            }
            else if (s[i] == 'X')
            {
                unsigned int    n = va_arg(args, unsigned int);
                taille += ft_printf_hex(n, "0123456789ABCDEF");
            }
            else if (s[i] == '%')
            {
                write(1, '%', 1);
                taille++;
            }
        }
        i++;
    }
    return (taille);
}