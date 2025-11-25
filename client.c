
#include "minitalk.h"

static int	parse_pid(const char *str, pid_t *pid)
{
	int		i;
	long	value;

	if (!str || !str[0])
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	value = 0;
	i = 0;
	while (str[i])
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (value <= 0)
		return (1);
	*pid = (pid_t)value;
	return (0);
}

static int	send_char(pid_t pid, unsigned char c, useconds_t gap)
{
	int	bit;
	int	one;
	int	ret;

	bit = 0;
	while (bit < 8)
	{
		one = (c >> bit) & 1;
		if (one == 1)
			ret = kill(pid, SIGUSR2);
		else
			ret = kill(pid, SIGUSR1);
		if (ret == -1)
			return (1);
		usleep(gap);
		bit++;
	}
	return (0);
}

static int	send_message(pid_t pid, const char *msg, useconds_t gap)
{
	int	i;
	int	ret;

	i = 0;
	while (1)
	{
		ret = send_char(pid, (unsigned char)msg[i], gap);
		if (ret != 0)
			return (1);
		if (msg[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	useconds_t	gap;
	int			ret;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> \"message\"\n", argv[0]);
		return (1);
	}
	if (parse_pid(argv[1], &server_pid) != 0)
	{
		ft_printf("Error: invalid PID\n");
		return (1);
	}
	gap = 200;
	ret = send_message(server_pid, argv[2], gap);
	if (ret != 0)
	{
		ft_printf("Error sending message\n");
		return (1);
	}
	return (0);
}
