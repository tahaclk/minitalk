/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:59:24 by tcelik            #+#    #+#             */
/*   Updated: 2022/11/11 16:00:45 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = (c << 1) + 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
