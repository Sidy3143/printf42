/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/11/14 15:45:50 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/18 21:30:17 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_str(va_list args)
{
	int		taille;
	char	*str;

	taille = 0;
	str = va_arg(args, char *);
	if (!str)
		taille += ft_printf_str("(null)");
	else
		taille += ft_printf_str(str);
	return (taille);
}

int	ft_check_ptr(va_list args)
{
	int			taille;
	void		*ptr;
	uintptr_t	adress;

	taille = 0;
	ptr = va_arg(args, void *);
	if (!ptr)
		taille += ft_printf_str("(nil)");
	else
	{
		adress = (uintptr_t)ptr;
		taille += ft_printf_hex_adress(adress, "0123456789abcdef");
	}
	return (taille);
}

int	ft_print_type(char c, va_list args)
{
	int	taille;

	taille = 0;
	if (c == 'c')
		taille += ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		taille += ft_check_str(args);
	else if (c == 'i' || c == 'd')
		taille += ft_printf_int(va_arg(args, int));
	else if (c == 'u')
		taille += ft_printf_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'p')
		taille += ft_check_ptr(args);
	else if (c == 'x')
		taille += ft_printf_hex(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		taille += ft_printf_hex(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (c == '%')
	{
		write(1, "%", 1);
		taille++;
	}
	return (taille);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		taille;
	va_list	args;

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
		else if (s[i + 1])
		{
			i++;
			taille += ft_print_type(s[i], args);
		}
		i++;
	}
	return (taille);
}
/*
int	main(void)
{
	int taille;
	int *ptr;

	ptr = &taille;
	taille = ft_printf("Hello, I am %s.\n", "Sidy");
	ft_printf("---Taille: %d---\n", taille);

	taille = ft_printf("Adress of taille is %p.\n", "Sidy", ptr);
	ft_printf("---Taille: %d---\n", taille);

	taille = ft_printf("%d in hexadecimal is %x.\n", 42, 42);
	printf("---Taille: %d---\n", taille);

	return(0);
}*/