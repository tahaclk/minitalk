/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intprinter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:19:02 by tcelik            #+#    #+#             */
/*   Updated: 2022/10/15 17:58:50 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_counter(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_pitoa(int n)
{
	char		*str;
	int			l;
	long int	tmp;

	tmp = n;
	l = digit_counter(tmp);
	str = (char *)malloc(l + 1);
	if (!str)
		return (NULL);
	str[l] = '\0';
	if (tmp < 0)
	{
		str[0] = '-';
		tmp = tmp * -1;
	}
	if (tmp == 0)
		str[0] = '0';
	while (tmp > 0)
	{
		str[--l] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (str);
}

int	ft_intprinter(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_pitoa(n);
	len = ft_strprinter(num);
	free(num);
	return (len);
}
