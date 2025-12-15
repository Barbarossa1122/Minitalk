/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fionni <fionni@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 15:54:00 by fionni            #+#    #+#             */
/*   Updated: 2025-12-15 15:54:00 by fionni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_server
{
	unsigned char	c;
	int				bit_index;
	pid_t			sender_pid;
}	t_server;

#endif
