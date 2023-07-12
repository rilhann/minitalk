/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:53:51 by ruilhan          #+#    #+#             */
/*   Updated: 2022/03/02 14:54:22 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_checker(va_list *args, char s);
int		ft_putstr(char *s);
int		ft_putnbr(int a, int *s);
int		ft_putchar(char c);

int		ft_atoi(const char *str);

void	kill_checker(pid_t pid, int sig);
void	send_bit(unsigned char c, pid_t pid);
void	get_pid(void);

#endif