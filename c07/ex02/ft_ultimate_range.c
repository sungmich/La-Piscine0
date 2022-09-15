/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:17:59 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/07 14:47:33 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	int			*rg;
	long long	val;

	i = 0;
	val = max - min;
	if (min >= max)
	{
		range = 0;
		return (0);
	}
	rg = (int *)malloc(sizeof(int) * (val + 1));
	if (!rg)
		return (-1);
	while (min < max)
	{
		rg[i++] = min;
		min++;
	}
	*range = rg;
	return (val);
}
