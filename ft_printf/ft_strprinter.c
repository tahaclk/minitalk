/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:35:36 by tcelik            #+#    #+#             */
/*   Updated: 2022/10/15 18:32:09 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strprinter(char *str)
{
	int	i;

	i = 0;
	if (str)
	{	
		while (str[i])
			write(1, &str[i++], 1);
	}
	else
		i += write(1, "(null)", 6);
	return (i);
}
