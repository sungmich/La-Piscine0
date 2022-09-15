/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:44:50 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/30 20:43:02 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	cnt;

	cnt = 0;
	if (*str)
	{
		while (*str)
		{
			cnt++;
			str++;
		}
	}
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	s_len;
	unsigned int	d_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	if (size > d_len)
	{
		while (src[i] && d_len + i + 1 < size)
		{
			dest[d_len + i] = src[i];
			i++;
		}
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
