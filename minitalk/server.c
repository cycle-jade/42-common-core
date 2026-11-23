#include "mini.h"

void	decompose(int signum)
{
	static unsigned char	c = 0;
	static int				counter = 0;

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
		if (!c)
			ft_printf("\n");
		c = 0;
		counter = 0;
	}
}

int	main(void)
{
	ft_printf("███████ ███████ ███████ ██    ██ ███████ ███████  \n");
	ft_printf("██      ██      ██   ██ ██    ██ ██      ██   ██ \n");
	ft_printf("███████ █████   ██████  ██    ██ █████   ██████  \n");
	ft_printf("     ██ ██      ██   ██  ██  ██  ██      ██   ██ \n");
	ft_printf("███████ ███████ ██   ██   ████   ███████ ██   ██ \n");
	ft_printf("                                                 \n");
	ft_printf("                                                  \n");
	ft_printf("PID: %d \n", getpid());
	while (1)
	{
		signal(SIGUSR1, decompose);
		signal(SIGUSR2, decompose);
	}
	return (0);
}
