/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:40:17 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/04 18:40:14 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(long nbr_long, char *base, int base_len)
{
	if (nbr_long == 0)
		return ;
	ft_print(nbr_long / (long)base_len, base, base_len);
	write(1, &base[nbr_long % (long)base_len], 1);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	if (!*base || !*(base + 1))
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nbr_long;

	nbr_long = (long)nbr;
	base_len = 0;
	if (ft_check(base) == 0)
		return ;
	while (base[base_len])
		base_len++;
	if (nbr_long < 0)
	{
		write(1, "-", 1);
		nbr_long = -nbr_long;
	}
	if (nbr_long == 0)
		write(1, &base[0], 1);
	else
		ft_print(nbr_long, base, base_len);
}
