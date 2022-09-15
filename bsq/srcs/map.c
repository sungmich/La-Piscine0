/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:37:49 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/15 05:37:51 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**malloc_map(char *content, t_variable *var)
{
	int		i;
	char	**map;
	int		j;
	int		k;

	k = 0;
	map = (char **)malloc (sizeof(char *) * (var->line + 1));
	i = 0;
	while (content[i] != '\n')
		i++;
	i++;
	j = i;
	while (content[i] != '\n')
		i++;
	j = i - j;
	while (k < var->line)
		map[k++] = (char *)malloc(sizeof(char) * (j + 1));
	return (map);
}

void	make_map(char *content, char **map)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = 0;
	while (content[i] != '\n')
		i++;
	while (content[++i])
	{
		if (content[i] == '\n')
		{
			map[j][k] = '\0';
			j++;
			k = 0;
			continue ;
		}
		map[j][k++] = content[i];
	}
	map[j] = 0;
}

void	ft_fill_min(char **map, int **our_map, t_variable *var)
{
	int	min;
	int	j;
	int	i;

	i = 0;
	while (++i < var->line)
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] == var->empty)
			{
				min = our_map[i - 1][j - 1];
				if (min > our_map[i][j - 1])
					min = our_map[i][j - 1];
				else if (min > our_map[i - 1][j])
					min = our_map[i - 1][j];
				our_map[i][j] = min + 1;
			}
			else
				our_map[i][j] = 0;
		}
	}
}

void	ft_fill_our_map(char **map, int **our_map, t_variable *var)
{
	int	i;

	i = -1;
	while (++i < var->line)
	{
		if (map[i][0] == var->obs)
			our_map[i][0] = 0;
		else
			our_map[i][0] = 1;
	}
	i = -1;
	while (map[0][++i])
	{		
		if (map[0][i] == var->obs)
			our_map[0][i] = 0;
		else
			our_map[0][i] = 1;
	}
	ft_fill_min(map, our_map, var);
}

int	**make_our_map(char **map, t_variable *var)
{
	int	i;
	int	j;
	int	k;
	int	**our_map;

	k = 0;
	i = 0;
	j = 0;
	our_map = (int **)malloc(sizeof(int *) * var->line);
	while (map[i][k])
		k++;
	while (j < var->line)
		our_map[j++] = (int *)malloc(sizeof(int) * k);
	ft_fill_our_map(map, our_map, var);
	return (our_map);
}
