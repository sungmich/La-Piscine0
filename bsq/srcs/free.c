/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:37:42 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/15 05:37:43 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_free_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (j < i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

void	ft_free_ourmap(int **our_map, char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (j < i)
	{
		free(our_map[j]);
		j++;
	}
	free(our_map);
}
