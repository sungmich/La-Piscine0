/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:59:39 by sungmich          #+#    #+#             */
/*   Updated: 2022/08/28 16:35:42 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *visited)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		if (visited[i] == 1)
		{
			c = '0' + i;
			write(1, &c, 1);
		}
		i++;
	}
}

int	ft_check_last(int n, int *visited)
{
	int	cnt;
	int	i;

	i = 1;
	cnt = 0;
	while (i <= n)
	{
		if (visited[10 - i] == 1)
			cnt++;
		i++;
	}
	if (cnt == n)
		return (1);
	else
		return (0);
}

void	dfs(int cnt, int n, int i, int *visited)
{
	if (cnt == n)
	{
		ft_print(visited);
		if (!ft_check_last(n, visited))
			write(1, ", ", 2);
	}
	while (i < 10)
	{
		visited[i] = 1;
		dfs (cnt + 1, n, i + 1, visited);
		visited[i] = 0;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	visited[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		visited[i] = 0;
		i++;
	}
	dfs(0, n, 0, visited);
}
