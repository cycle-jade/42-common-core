#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (nmemb > SIZE_MAX / size)
		return (NULL);
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	if (nmemb == SIZE_MAX)
		return (NULL);
	if (size == SIZE_MAX)
		return (NULL);
	ft_bzero(memory, nmemb * size);
	return (memory);
}
