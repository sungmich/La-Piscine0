/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:29:02 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/29 15:13:45 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*p;
	char	*q;

	p = src;
	q = dest;
	while (*p)
	{
		*(q++) = *p++;
	}
	*q = *p;
	return (dest);
}
