/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:39:19 by fionni            #+#    #+#             */
/*   Updated: 2025/03/02 14:43:12 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr(unsigned long nb)
{
	char	*hexa;
	int		output;

	hexa = "0123456789abcdef";
	output = 0;
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (nb >= 16)
		output += ft_put_ptr(nb / 16);
	output += write(1, &hexa[nb % 16], 1);
	return (output);
}

int	ft_printptr(va_list arg)
{
	unsigned long	nbr;

	nbr = va_arg(arg, unsigned long);
	if (nbr == 0)
		return (ft_put_ptr(nbr));
	else
	{
		ft_putchar('0');
		ft_putchar('x');
		return (ft_put_ptr(nbr) + 2);
	}
}
