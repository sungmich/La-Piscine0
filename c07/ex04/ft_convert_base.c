/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:30:57 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/07 14:47:09 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_result(char *str, char *base);
int	ft_find_index(char *base, char c);
int	ft_check(char *base);
int	ft_atoi_base(char *str, char *base);

void	ft_func(char *arr, int cnt, long long num, char *base)
{
	int	i;
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (num < 0)
	{
		arr[0] = '-';
		ft_func(arr + 1, cnt - 1, -num, base);
		return ;
	}
	i = cnt - 1;
	while (i >= 0)
	{
		arr[i--] = base[num % base_len];
		num /= base_len;
	}
	arr[cnt] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	char		*arr;
	int			cnt;
	int			base_to_len;

	if (ft_check(base_from) == 0 || ft_check(base_to) == 0)
		return (NULL);
	cnt = 0;
	num = (long long)ft_atoi_base(nbr, base_from);
	base_to_len = 0;
	while (base_to[base_to_len])
		base_to_len++;
	while (num != 0)
	{
		cnt++;
		num /= base_to_len;
	}
	num = (long long)ft_atoi_base(nbr, base_from);
	if (num <= 0)
		cnt++;
	arr = (char *)malloc(sizeof(char) * (cnt + 1));
	ft_func(arr, cnt, num, base_to);
	return (arr);
}
