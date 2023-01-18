/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:57:54 by tcelik            #+#    #+#             */
/*   Updated: 2022/11/14 15:52:38 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_sayac;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_sayac--;
	if (g_sayac == 0)
		write(1, "Basarili\n", 9);
}

void	signal_sender(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (j++ < 8)
		{
			if ((str[i] & 128) != 128)
				kill(pid, SIGUSR1);
			else if ((str[i] & 128) == 128)
				kill(pid, SIGUSR2);
			str[i] = str[i] << 1;
			usleep(110);
		}
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

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
	int		pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	g_sayac = ft_strlen(argv[2]);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	signal_sender(pid, argv[2]);
	return (0);
}
