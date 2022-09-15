/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:57:40 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/30 21:48:21 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_find(char *str, char *to_find)
{
	char	*s;
	char	*t;

	s = str;
	t = to_find;
	if (*t == *s)
	{
		while (*t)
		{
			if (*s != *t)
				return (0);
			s++;
			t++;
		}
		return (1);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (ft_find(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
