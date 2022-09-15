/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:24:10 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/07 14:47:27 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	func(char *ans, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			ans[k] = strs[i][j];
			j++;
			k++;
		}
		i++;
		j = 0;
		while (sep[j] && i < size)
		{
			ans[k] = sep[j];
			k++;
			j++;
		}
	}
	ans[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	int		j;
	char	*ans;

	total_len = 0;
	i = -1;
	if (size <= 0)
	{
		ans = (char *)malloc(sizeof(char));
		return (ans);
	}
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		total_len += j;
	}
	j = 0;
	while (sep[j])
		j++;
	ans = (char *)malloc(sizeof(char) * (total_len + (size - 1) * j + 1));
	func(ans, strs, sep, size);
	return (ans);
}
