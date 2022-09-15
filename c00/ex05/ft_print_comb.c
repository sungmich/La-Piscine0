/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:13:49 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/28 16:29:48 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	num_end(int i, int j, int k)
{
	if (i == 7 && j == 8 && k == 9)
		return (1);
	else
		return (0);
}

void	ft_print_three_num(int i, int j, int k)
{
	char	num[3];

	num[0] = i + '0';
	num[1] = j + '0';
	num[2] = k + '0';
	write(1, num, 3);
	if (!num_end(i, j, k))
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 2;
	while (i < j)
	{
		j = i + 1;
		while (j < k)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_print_three_num(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
