
#include "minitalk_bonus.h"

t_server    g_srv;

static void	init_server_state_bonus(void)
{
	g_srv.c = 0;
	g_srv.bit_index = 0;
	g_srv.sender_pid = 0;
}

static void	handle_bit_bonus(int signum, siginfo_t *info, void *context)
{
	(void)context;

	if (g_srv.sender_pid == 0)
		g_srv.sender_pid = info->si_pid;
	else if (info->si_pid != g_srv.sender_pid)
	{
		g_srv.c = 0;
		g_srv.bit_index = 0;
		g_srv.sender_pid = info->si_pid;
	}
	if (signum == SIGUSR2)
		g_srv.c |= (1 << g_srv.bit_index);
	g_srv.bit_index++;
	if (g_srv.bit_index == 8)
	{
		if (g_srv.c == '\0')
		{
			write(1, "\n", 1);
			kill(g_srv.sender_pid, SIGUSR1);
		}
		else
			write(1, &g_srv.c, 1);
		g_srv.c = 0;
		g_srv.bit_index = 0;
	}
}

static int	setup_signals_bonus(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handle_bit_bonus;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	return (0);
}

int main(void)
{
    init_server_state_bonus();
    ft_printf("Server PID: %d\n", getpid());
    if (setup_signals_bonus() != 0)
    {
        write(2, "Error: sigaction\n", 17);
        return (1);
    }
    while (1)
        pause();
    return (0);
}
