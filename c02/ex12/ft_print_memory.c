/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:52:47 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/11 23:14:32 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr(unsigned long long addr, int n)
{
	if (n < 16)
	{
		ft_print_addr(addr / 16, n + 1);
		write(1, &"0123456789abcdef"[addr % 16], 1);
	}
}

void	ft_print_hex(char *str, unsigned int i, unsigned int size)
{
	unsigned int	cnt;

	cnt = i;
	while (cnt < i + 16 && cnt < size)
	{
		write(1, &("0123456789abcdef"[str[cnt] / 16]), 1);
		write(1, &("0123456789abcdef"[str[cnt] % 16]), 1);
		if (cnt % 2 == 1)
			write(1, " ", 1);
		cnt++;
	}
	while (cnt < i + 16)
	{
		if (cnt % 2 == 1)
			write(1, " ", 1);
		write(1, "  ", 2);
		cnt++;
	}
}

void	ft_write(char *str, unsigned int i)
{
	unsigned int	cnt;

	cnt = i;
	while (cnt < i + 16 && str[cnt])
	{
		if (str[cnt] < 32 || str[cnt] > 126)
			str[cnt] = '.';
		write(1, &str[cnt], 1);
		cnt++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*str;

	if (!size)
		return (addr);
	i = 0;
	str = (char *)addr;
	while (i < size)
	{
		ft_print_addr((unsigned long long)addr + i, 0);
		write(1, ": ", 2);
		ft_print_hex(str, i, size);
		ft_write(str, i);
		i += 16;
		if (i >= size)
			write(1, ".", 1);
		write(1, "\n", 1);
	}
	return (addr);
}
int main()
{
	char   s12[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
    ft_print_memory((void *)s12, sizeof(s12));
    return (0);
}
