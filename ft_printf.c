/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:48:11 by ruilhan          #+#    #+#             */
/*   Updated: 2022/03/02 12:58:50 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int a, int *s)
{
	if (a == -2147483648)
	{
		*s += ft_putchar('-');
		*s += ft_putchar('2');
		a = 147483648;
	}
	if (a < 0)
	{
		*s += ft_putchar('-');
		a *= -1;
	}
	if (a >= 0 && a <= 9)
	{
		*s += ft_putchar(a + 48);
	}
	if (a > 9)
	{
		ft_putnbr(a / 10, s);
		ft_putnbr(a % 10, s);
	}
	return (*s);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_checker(va_list *args, char s)
{
	int	result;

	result = 0;
	if (s == 'd')
		ft_putnbr(va_arg(*args, int), &result);
	if (s == 's')
		result += ft_putstr(va_arg(*args, char *));
	if (s == 'c')
		result += ft_putchar(va_arg(*args, int));
	return (result);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		result;
	va_list	args;

	i = 0;
	result = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			result += ft_checker(&args, s[i]);
		}
		else
		{
			result += write(1, &s[i], 1);
		}
		i++;
	}
	return (result);
}
