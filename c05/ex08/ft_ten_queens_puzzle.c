/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:17:10 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/03 14:02:05 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_q(int *q)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = q[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check(int *q, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		if (q[n] == q[i] || q[i] - q[n] == i - n || q[i] - q[n] == n - i)
			return (0);
		n++;
	}
	return (1);
}

void	recur(int *q, int i, int *cnt)
{
	q[i] = 0;
	while (q[i] <= 9)
	{
		if (check(q, i))
		{
			if (i == 9)
			{
				print_q(q);
				(*cnt)++;
			}
			else
				recur(q, i + 1, cnt);
		}
		q[i]++;
	}	
}

int	ft_ten_queens_puzzle(void)
{
	int	q[10];
	int	cnt;

	cnt = 0;
	recur(q, 0, &cnt);
	return (cnt);
}
