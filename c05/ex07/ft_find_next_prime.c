/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:16:10 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/03 15:40:20 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_find_next_prime(int nb)
{
	int	i;
	int	flag;

	i = 2;
	flag = 0;
	if (nb < 3)
		return (2);
	while (1)
	{
		while (i <= nb / i)
		{
			if (nb % i == 0)
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 0)
			return (nb);
		i = 2;
		flag = 0;
		nb++;
	}
}
