/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:37:29 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/15 05:37:31 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_line_length(char *content)
{
	int	i;
	int	j;
	int	len;
	int	ex_j;

	i = 0;
	while (content[i] != '\n')
		i++;
	len = i++;
	while (content[i] != '\n')
		i++;
	len = i - len - 1;
	j = i;
	ex_j = j;
	while (content[++j])
	{
		if (content[j] == '\n')
		{
			if (j - ex_j - 1 != len)
				return (1);
			ex_j = j;
		}
	}
	return (0);
}

int	ft_check_line(char *content, t_variable *var)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			cnt++;
		i++;
	}
	init_var(content, var);
	if (var->line != cnt - 1)
		return (1);
	return (0);
}

int	ft_check_var_put(char *content, int i, int j)
{
	int	k;

	while (j < i)
	{
		k = j;
		while (++k < i)
		{
			if (content[k] == content[j])
				return (1);
		}
		j++;
	}
	return (0);
}

int	ft_check_var(char *content)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (content[i] != '\n' && content[i])
		i++;
	if (i < 4)
		return (1);
	while (++j < i - 3)
	{
		if (!('0' <= content[j] && content[j] <= '9'))
			return (1);
	}
	if (ft_check_var_put(content, i, j))
		return (1);
	return (0);
}

int	ft_error(char *content, t_variable *var)
{
	if (ft_check_var(content))
		return (1);
	if (ft_check_line_length(content))
		return (1);
	if (ft_check_line(content, var))
		return (1);
	return (0);
}
