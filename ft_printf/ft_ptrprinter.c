/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:14:13 by tcelik            #+#    #+#             */
/*   Updated: 2022/10/15 18:31:42 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(unsigned long long ptr)
{
	char	*chrs;

	chrs = "0123456789abcdef";
	if (ptr > 0)
		ft_put_ptr(ptr / 16);
	if (ptr != 0)
		ft_chrprinter(chrs[ptr % 16]);
}

static int	ft_ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_ptrprinter(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
