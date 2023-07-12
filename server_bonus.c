/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:53:26 by ruilhan          #+#    #+#             */
/*   Updated: 2022/03/05 19:50:46 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	kill_checker(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Hatalı yollama yaplıdı\n");
		exit(1);
	}
}

void	get_pid(void)
{
	int	i;

	i = getpid();
	ft_printf("%d\n", i);
}

void	set_signal(int sig, siginfo_t *info, void *cnt)
{
	static int	g_number;
	static int	g_bit_count;

	(void)cnt;
	g_number <<= 1;
	if (sig == SIGUSR1)
	{
		g_number |= 1;
	}
	g_bit_count++;
	if (g_bit_count == 8)
	{
		ft_printf("%c", g_number);
		if (g_number == 0)
		{
			ft_printf("\nMesaj bu PİD'den gelmiştir : %d\n", info->si_pid);
			kill_checker(info->si_pid, SIGUSR1);
		}
		g_number = 0;
		g_bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	(void)argc;
	(void)argv;
	sig.sa_sigaction = &set_signal;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		return (-1);
	get_pid();
	while (1)
		continue ;
}
