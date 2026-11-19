/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/11/16 11:52:51 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/18 21:16:55 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_str(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_printf_int(int n)
{
	int taille;

	taille = 0;
	if (n == -2147483648)
	{
		taille = ft_printf_str("-2147483648");
		return (taille);
	}
	if (n < 0)
	{
		taille += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		taille += ft_printf_int(n / 10);
	taille += ft_putchar((n % 10) + '0');
	return (taille);
}

int	ft_printf_unsigned_int(unsigned int n)
{
	int taille;

	taille = 0;
	if (n > 9)
		taille += ft_printf_unsigned_int(n / 10);
	taille += ft_putchar((n % 10) + '0');
	return (taille);
}

static int	ft_printf_hex_recursive(uintptr_t n, char *base)
{
	int taille;

	taille = 0;
	if (n > 15)
	{
		taille += ft_printf_hex_recursive(n / 16, base);
	}
	taille += ft_putchar(base[n % 16]);
	return (taille);
}

int	ft_printf_hex(uintptr_t n, char *base)
{
	return (ft_printf_hex_recursive(n, base));
}

int	ft_printf_hex_adress(uintptr_t n, char *base)
{
	int taille;

	taille = write(1, "0x", 2);
	taille += ft_printf_hex_recursive(n, base);
	return (taille);
}

/*
int	main(void)
{
	int taille = ft_printf_hex(423, "0123456789abcdef");
	printf("\ntaille: %d\n", taille);
}*/