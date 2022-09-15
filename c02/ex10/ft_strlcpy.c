/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:57:35 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/29 16:57:02 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned	int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*p;
	unsigned int	i;
	unsigned int	len;

	i = 1;
	p = src;
	while (*p && i < size)
	{
		*dest++ = *p++;
		i++;
	}
	*dest = '\0';
	len = ft_strlen(src);
	return (len);
}
