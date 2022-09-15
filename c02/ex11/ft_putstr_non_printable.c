/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:59:14 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/30 17:01:59 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_printable(unsigned char c)
{
	if ((0 < c && c < 32) || c > 126)
		return (0);
	else
		return (1);
}

void	ft_hex(unsigned char c)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!ft_is_printable((unsigned char) *str))
			ft_hex((unsigned char) *str);
		else
			write(1, str, 1);
		str++;
	}
}
