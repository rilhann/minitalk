/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:46:41 by ruilhan          #+#    #+#             */
/*   Updated: 2022/03/07 11:12:14 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	kill_checker(int sig, pid_t pid)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Hatalı sinyal yolladınız.");
		exit(1);
	}
}

void	send_bit(unsigned char c, pid_t pid)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if ((c >> count) & 1)
		{
			kill_checker(SIGUSR1, pid);
		}
		else
		{
			kill_checker(SIGUSR2, pid);
		}
		count--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	char	*data;

	i = 2;
	if (argc < 3)
		return (1);
	pid = ft_atoi(argv[1]);
	while (i < argc)
	{
		data = argv[i];
		while (*data)
			send_bit(*data++, pid);
		send_bit(' ', pid);
		i++;
	}
	send_bit('\0', pid);
	return (0);
}
