/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:04:20 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/07 22:43:02 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i])
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			len;
	t_stock_str	*s;

	i = 0;
	s = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (s == NULL)
		return (NULL);
	while (i < ac)
	{
		len = 0;
		while (av[i][len])
			len++;
		s[i].size = len;
		s[i].str = av[i];
		s[i].copy = ft_strdup(av[i]);
		i++;
	}
	s[i].str = 0;
	return (s);
}
