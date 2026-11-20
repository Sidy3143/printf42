/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:47:56 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/20 15:34:53 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_hex_recursive(uintptr_t n, char *base)
{
	int	taille;

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
	int	taille;

	taille = write(1, "0x", 2);
	taille += ft_printf_hex_recursive(n, base);
	return (taille);
}
