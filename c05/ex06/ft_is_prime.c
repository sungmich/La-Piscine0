/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:40 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/03 18:07:01 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	flag;
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	flag = 0;
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
		return (1);
	return (0);
}
