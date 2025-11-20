/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:21:07 by fionni            #+#    #+#             */
/*   Updated: 2025/03/02 18:44:15 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned(unsigned int nb)
{
	char	*hexa;
	int		output;

	hexa = "0123456789";
	output = 0;
	if (nb == 0)
	{
		output += write(1, "0", 1);
		return (output);
	}
	if (nb >= 10)
		output += ft_putnbr_unsigned(nb / 10);
	output += write(1, &hexa[nb % 10], 1);
	return (output);
}

int	ft_printunsint(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return (ft_putnbr_unsigned(nb));
}
