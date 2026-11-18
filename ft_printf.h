/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindiaye <sindiaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:46:07 by sindiaye          #+#    #+#             */
/*   Updated: 2026/11/18 21:18:21 by sindiaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

int ft_printf(const char *, ...);
int ft_printf_hex(uintptr_t n, char *base);
int ft_printf_int(int n);
int ft_printf_str(char *str);
int ft_putchar(char c);


#endif