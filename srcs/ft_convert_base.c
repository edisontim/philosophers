#include "philo_bonus.h"

int	ft_strlen_conv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_convert_base(char *nbr)
{
	char	*to_return;
	int		index;
	int		to_malloc;
	int		to_return_index;
	int		i;

	i = 0;
	index = 0;
	to_return_index = 0;
	to_malloc = 8 * ft_strlen_conv(nbr);
	to_return = malloc(sizeof(*to_return) * (to_malloc + 1));
	if (to_return == NULL)
		return (NULL);
	while (nbr[index])
	{
		i = 7;
		while (i >= 0)
			to_return[to_return_index++] = ((nbr[index] >> i--) & 0x01) + 48;
		index++;
	}
	to_return[to_return_index] = 0;
	return (to_return);
}
