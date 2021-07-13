#include "philo.h"

int	ft_strlen(char *s, int *index, int *j)
{
	int	i;

	i = 0;
	*index = 0;
	*j = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	int		s1_l;
	int		s2_l;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1_l = ft_strlen(s1, &i, &j);
	s2_l = ft_strlen(s2, &i, &j);
	final = malloc(sizeof(*final) * (s1_l + s2_l + 1));
	if (!final)
		return (NULL);
	while (i < (s1_l + s2_l))
	{
		if (i < s1_l)
			final[i] = s1[i];
		else
			final[i] = s2[j++];
		i++;
	}
	free(s1);
	final[i] = '\0';
	return (final);
}
