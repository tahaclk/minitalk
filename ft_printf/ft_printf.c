/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:13:01 by tcelik            #+#    #+#             */
/*   Updated: 2022/10/15 18:42:44 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ag_printer(const char chr, va_list ag)
{
	int	r;

	r = 0;
	if (chr == 'c')
		r += ft_chrprinter(va_arg(ag, int));
	else if (chr == 's')
		r += ft_strprinter(va_arg(ag, char *));
	else if (chr == 'p')
		r += ft_ptrprinter(va_arg(ag, unsigned long long));
	else if (chr == 'd' || chr == 'i')
		r += ft_intprinter(va_arg(ag, int));
	else if (chr == 'u')
		r += ft_unintprinter(va_arg(ag, unsigned int));
	else if (chr == 'x')
		r += ft_hexprinter(va_arg(ag, unsigned int), chr);
	else if (chr == 'X')
		r += ft_hexprinter(va_arg(ag, unsigned int), chr);
	else if (chr == '%')
		r += ft_chrprinter('%');
	return (r);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		r;
	va_list	ag;

	i = -1;
	r = 0;
	va_start(ag, str);
	while (str[++i])
	{
		if (str[i] == '%')
			r += ag_printer(str[++i], ag);
		else
		{
			write(1, &str[i], 1);
			r++;
		}
	}
	va_end(ag);
	return (r);
}
