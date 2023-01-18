/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:58:24 by tcelik            #+#    #+#             */
/*   Updated: 2022/10/15 18:32:25 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		l++;
	}
	return (l);
}

void	ft_rec_hex(unsigned int n, int c)
{
	if (n > 0)
		ft_rec_hex(n / 16, c);
	if (n != 0)
	{
		if (n % 16 <= 9)
			ft_chrprinter(n % 16 + '0');
		if ((n % 16 < 16) && (n % 16 > 9) && c == 'x')
			ft_chrprinter((n % 16) - 10 + 'a');
		if ((n % 16 < 16) && (n % 16 > 9) && c == 'X')
			ft_chrprinter((n % 16) - 10 + 'A');
	}
}

int	ft_hexprinter(unsigned int n, int c)
{
	int	l;

	if (n != 0)
		ft_rec_hex(n, c);
	else
		write(1, "0", 1);
	l = hex_len(n);
	return (l);
}
