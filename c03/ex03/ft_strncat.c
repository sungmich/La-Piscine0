/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:54:11 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/28 22:18:17 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*d;
	char			*s;
	unsigned int	i;

	i = 0;
	d = dest;
	s = src;
	while (*d)
		d++;
	while (*s && i < nb)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	*d = '\0';
	return (dest);
}
