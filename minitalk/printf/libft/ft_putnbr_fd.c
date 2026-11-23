#include "libft.h"
#include <unistd.h>

int	count_digitz(int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*num_str;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
		write(fd, "2147483648", 10);
	else
	{
		num_str = ft_itoa(n);
		write(fd, num_str, count_digitz(n));
		free(num_str);
	}
}
