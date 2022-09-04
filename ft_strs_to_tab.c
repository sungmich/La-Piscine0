#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *str)
{
	char	*s;
	int	i;

	i = 0;
	while (str[i])
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int		i;
	int		len;
	t_stock_str	*s;

	i = 1;
	s = (t_stock_str *)malloc(sizoef(t_stock_str) * ac);
	if (s == NULL)
		return (NULL);
	while (i < ac)
	{
		len = 0;
		while (av[i][len])
			len++;
		s[i - 1].size = len;
		s[i - 1].str = av[i];
		s[i - 1].copy = ft_strdup(av[i]);
		i++;
	}
	s[i - 1].str = 0;
	return (s);
}
