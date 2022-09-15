/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:10:40 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/03 14:01:37 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	num;

	if (nb < 0)
		return (0);
	num = 1;
	while (nb > 0)
	{
		num *= nb;
		nb--;
	}
	return (num);
}
