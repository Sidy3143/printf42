/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:45:50 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/18 21:30:17 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    int i;
    int taille;
    va_list args;

    if (!s)
        return (-1);
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
        else if s[i + 1]
        {
            i++;
            if (s[i] == 'c')
            {
                char c = va_arg(args, int);
                taille += ft_putchar(c);
            }
            else if (s[i] == 's')
            {
                char    *str = va_arg(args, char *);
                if (!str)
                    taille += ft_printf_str("(null)");
                else
                    taille += ft_printf_str(str);
            }
            else if (s[i] == 'i' || s[i] == 'd')
            {
                int n = va_arg(args, int);
                taille += ft_printf_int(n);
            }
            else if (s[i] == 'u')
            {
                unsigned int n = va_arg(args, unsigned int);
                taille += ft_printf_unsigned_int(n);
            }
            else if (s[i] == 'p')
            {
                void    *ptr = va_arg(args, void *);
                if (!ptr)
                    taille += ft_printf_str("(nil)");
                else
                {
                    uintptr_t   adress = (uintptr_t)ptr;
                    taille += ft_printf_hex_adress(adress, "0123456789abcdef");
                }
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
                write(1, "%", 1);
                taille++;
            }
        }
        i++;
    }
    return (taille);
}
/*
int main(void)
{
    int taille;
    int *ptr;
    
    ptr = &taille;
    taille = ft_printf("Hello, I am %s.\n", "Sidy");
    ft_printf("---Taille: %d---\n", taille);

    taille = ft_printf("Adress of taille is %p.\n", "Sidy", ptr);
    ft_printf("---Taille: %d---\n", taille);

    taille = ft_printf("taille is %p.\n", "Sidy", ptr);
    ft_printf("---Taille: %d\n---", taille);

    taille = ft_printf("%d in hexadecimal is %x.\n", 42, 42);
    printf("---Taille: %d\n---", taille);

    return(0);
}*/