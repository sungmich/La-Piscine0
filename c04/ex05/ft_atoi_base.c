/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:28:57 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/04 19:56:00 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_find_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_result(char *str, char *base, int base_len)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (ft_find_index(base, str[i]) != -1 && str[i])
	{
		num *= base_len;
		num += ft_find_index(base, str[i]);
		i++;
	}
	return (num);
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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '\r' || base[i] == '\f')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	minus_cnt;
	int	i;

	i = 0;
	base_len = 0;
	minus_cnt = 0;
	if (ft_check(base) == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus_cnt++;
	}
	while (base[base_len])
		base_len++;
	if (minus_cnt % 2 == 1)
		return (-ft_result(str + i, base, base_len));
	return (ft_result(str + i, base, base_len));
}
