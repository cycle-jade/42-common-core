#include "mini.h"

void	resend(siginfo_t *siginfo, unsigned char c)
{
	kill(siginfo->si_pid, SIGUSR1);
	if (!c)
	{
		ft_printf("\n");
		ft_printf("Received signals from: %d\n", siginfo->si_pid);
		kill(siginfo->si_pid, SIGUSR2);
	}
}

void	decompose(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;
	static int				counter = 0;

	(void)context;
	(void)siginfo;
	if (signum == SIGUSR1)
		c = c << 1;
	else if (signum == SIGUSR2)
	{
		c = c << 1;
		c = (c | 1);
	}
	counter++;
	if (counter == 8)
	{
		ft_printf("%c", c);
		resend(siginfo, c);
		c = 0;
		counter = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("███████ ███████ ███████ ██    ██ ███████ ███████  \n");
	ft_printf("██      ██      ██   ██ ██    ██ ██      ██   ██ \n");
	ft_printf("███████ █████   ██████  ██    ██ █████   ██████  \n");
	ft_printf("     ██ ██      ██   ██  ██  ██  ██      ██   ██ \n");
	ft_printf("███████ ███████ ██   ██   ████   ███████ ██   ██ \n");
	ft_printf("                                                 \n");
	ft_printf("                                                  \n");
	ft_printf("PID: %d \n", getpid());
	sa.sa_sigaction = decompose;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
