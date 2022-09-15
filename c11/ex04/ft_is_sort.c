/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:34:26 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/10 17:53:12 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) * flag < 0)
			return (0);
		if (f(tab[i], tab[i + 1]) > 0)
			flag = 1;
		else if (f(tab[i], tab[i + 1]) < 0)
			flag = -1;
		i++;
	}
	return (1);
}
