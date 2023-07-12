/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:53:22 by ruilhan          #+#    #+#             */
/*   Updated: 2022/03/07 11:15:47 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	kill_checker(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Hatalı yolladınız\n");
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
			kill_checker(pid, SIGUSR1);
		}
		else
		{
			kill_checker(pid, SIGUSR2);
		}
		count--;
		usleep(100);
	}
}

void	sended_server(int sig)
{
	(void)sig;
	ft_printf("Bu mesaj serverdan gelmiştir");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*data;
	int		i;

	i = 2;
	if (argc < 3)
		return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sended_server);
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
