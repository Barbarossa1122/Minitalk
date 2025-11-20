/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexalower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:04:15 by fionni            #+#    #+#             */
/*   Updated: 2025/03/01 16:08:02 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hexalower(unsigned int nb)
{
	char	*hexa;
	int		output;

	hexa = "0123456789abcdef";
	output = 0;
	if (nb == 0)
	{
		output += write(1, "0", 1);
		return (output);
	}
	if (nb >= 16)
		output += ft_putnbr_hexalower(nb / 16);
	output += write(1, &hexa[nb % 16], 1);
	return (output);
}

int	ft_printhexalower(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return (ft_putnbr_hexalower(nb));
}
