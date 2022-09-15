/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:28:40 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/29 17:14:01 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_check(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*p;

	p = str;
	if (*str)
	{
		if ('a' <= *p && *p <= 'z')
			*p -= 32;
	}
	p++;
	while (*p)
	{
		if (!ft_char_check(*(p - 1)))
		{
			if ('a' <= *p && *p <= 'z')
				*p -= 32;
		}
		else if ('A' <= *p && *p <= 'Z')
		{
			if (ft_char_check(*(p - 1)))
				*p += 32;
		}
		p++;
	}
	return (str);
}
