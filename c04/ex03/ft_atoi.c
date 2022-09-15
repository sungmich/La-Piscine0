/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:19:58 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/04 20:02:53 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	minus_cnt;
	int	num;

	minus_cnt = 0;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus_cnt++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num *= 10;
		num += str[i++] - '0';
	}
	if (minus_cnt % 2 == 1)
		return (-num);
	return (num);
}
