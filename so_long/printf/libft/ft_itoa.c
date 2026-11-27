#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	count_digits(int n)
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

char	*integer_to_string(int n, int digits)
{
	char	*string;
	int		a;

	string = (char *)malloc((digits + 1) * sizeof(char));
	if (!string)
		return (NULL);
	if (n < 0)
	{
		a = 1;
		n = -n;
	}
	else
	{
		a = 0;
	}
	string[digits] = '\0';
	while (digits-- > a)
	{
		string[digits] = n % 10 + '0';
		n /= 10;
	}
	if (a)
		string[0] = '-';
	return (string);
}

char	*ft_itoa(int n)
{
	int	digits;

	if (n < 0)
		digits = count_digits(-n);
	else
		digits = count_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		digits++;
	return (integer_to_string(n, digits));
}
