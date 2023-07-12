/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:38:21 by ruilhan          #+#    #+#             */
/*   Updated: 2022/03/02 12:48:06 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			isaret;
	long int	sayi;

	i = 0;
	sayi = 0;
	isaret = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isaret *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sayi = (sayi * 10) + str[i] - '0';
		i++;
		if (sayi * isaret > 2147483647)
			return (-1);
		if (sayi * isaret < -2147483648)
			return (0);
	}
	return (sayi * isaret);
}
