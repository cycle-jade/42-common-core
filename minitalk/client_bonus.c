#include "mini.h"

void	binary(unsigned char cur, int pid)
{
	int				count;
	unsigned char	bit;

	count = 8;
	while (count-- > 0)
	{
		bit = (cur >> count & 1);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(700);
	}
}

void	print(int signum)
{
	static int	count = 0;

	if (signum == SIGUSR1)
		count++;
	if (signum == SIGUSR2)
	{
		count = count * 8;
		ft_printf("\n%d signals reception confirmed", count);
	}
}

void	crypting(int pid, char *str)
{
	while (*str != '\0')
	{
		binary(*str, pid);
		str++;
	}
	binary(*str, pid);
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = 0;
	if (argc == 3)
	{
		ft_printf("\nClient PID: %d ", getpid());
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, print);
		signal(SIGUSR2, print);
		crypting(pid, argv[2]);
	}
	return (0);
}
