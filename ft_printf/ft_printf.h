/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:28:53 by fionni            #+#    #+#             */
/*   Updated: 2025/03/02 18:44:41 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_printchar(va_list arg);
int		ft_printinteger(va_list arg);
int		ft_printstring(va_list arg);
int		ft_printhexalower(va_list arg);
int		ft_printhexaupper(va_list arg);
int		ft_printunsint(va_list arg);
int		ft_printpercent(char c);
int		ft_printptr(va_list arg);
int		ft_printf(const char *string, ...);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);

#endif
