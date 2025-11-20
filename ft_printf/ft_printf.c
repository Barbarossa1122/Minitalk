/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:33:55 by fionni            #+#    #+#             */
/*   Updated: 2025/03/02 18:44:54 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	argtoexe(va_list arg, char c)
{
	int	output;

	output = 0;
	if (c == 'c')
		output = ft_printchar(arg);
	else if (c == 's')
		output = ft_printstring(arg);
	else if (c == 'p')
		output = ft_printptr(arg);
	else if (c == 'd' || c == 'i')
		output = ft_printinteger(arg);
	else if (c == 'u')
		output = ft_printunsint(arg);
	else if (c == 'x')
		output = ft_printhexalower(arg);
	else if (c == 'X')
		output = ft_printhexaupper(arg);
	else if (c == '%')
		output = ft_printpercent(c);
	else
		return (0);
	return (output);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		i;
	int		output;

	i = 0;
	output = 0;
	va_start(arg, string);
	while (string[i])
	{
		if (string[i] != '%')
			output += ft_putchar(string[i]);
		else
		{
			output += argtoexe(arg, string[i + 1]);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (output);
}
