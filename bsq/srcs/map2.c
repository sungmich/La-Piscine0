/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:38:05 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/15 05:38:24 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_make_box_map(char **map, t_variable *var)
{
	int	i;
	int	j;

	i = var->max_x - var->max_width + 1;
	while (i <= var->max_x)
	{	
		j = var->max_y - var->max_width + 1;
		while (j <= var->max_y)
		{
			map[i][j] = var->box;
			j++;
		}
		i++;
	}
}

void	find_max_square(char **map, int **our_map, t_variable *var)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (i < var->line)
	{
		j = 0;
		while (map[i][j])
		{
			if (our_map[i][j] > max)
			{
				max = our_map[i][j];
				var->max_x = i;
				var->max_y = j;
				var->max_width = our_map[i][j];
			}
			j++;
		}
		i++;
	}
}

void	ft_print_map(char **map, t_variable *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->line)
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	ft_check_map(char **map, t_variable *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->line)
	{
		j = 0;
		if (map[i][j] == '\0')
			return (1);
		while (map[i][j])
		{
			if (map[i][j] != var->obs && map[i][j] != var->empty)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
