/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:57:54 by tcelik            #+#    #+#             */
/*   Updated: 2022/11/12 18:34:46 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while (str[c] == ' ' || str[c] == '\n' || str[c] == '\t'
		|| str[c] == '\v' || str[c] == '\f' || str[c] == '\r')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (res * 10) + (str[c] - '0');
		c++;
	}
	return (res * s);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		pid;

	i = 0;
	j = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		j = 0;
		while (j++ < 8)
		{
			if ((argv[2][i] & 128) != 128)
				kill(pid, SIGUSR1);
			else if ((argv[2][i] & 128) == 128)
				kill(pid, SIGUSR2);
			usleep(110);
			argv[2][i] = argv[2][i] << 1;
		}
		i++;
	}
	return (0);
}
