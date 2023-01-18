/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unintprinter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:37:06 by tcelik            #+#    #+#             */
/*   Updated: 2022/10/15 17:36:49 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_counter(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_un_itoa(unsigned int n)
{
	char			*str;
	int				l;
	unsigned int	tmp;

	tmp = n;
	l = digit_counter(tmp);
	str = (char *)malloc(l + 1);
	if (!str)
		return (NULL);
	str[l] = '\0';
	if (tmp == 0)
		str[0] = '0';
	while (tmp > 0)
	{
		str[--l] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (str);
}

int	ft_unintprinter(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_un_itoa(n);
	len = ft_strprinter(num);
	free(num);
	return (len);
}
