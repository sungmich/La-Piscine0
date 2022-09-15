/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:11:02 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/27 16:22:52 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	char	*p;

	p = str;
	while (*p)
	{
		if ('a' <= *p && *p <= 'z')
		{
			*p -= 32;
		}
		p++;
	}
	return (str);
}
