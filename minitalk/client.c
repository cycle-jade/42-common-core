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
		usleep(300);
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
		pid = ft_atoi(argv[1]);
		crypting(pid, argv[2]);
	}
	return (0);
}
