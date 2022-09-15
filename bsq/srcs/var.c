/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:37:59 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/15 05:38:13 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_file(char *file)
{
	int	fd;
	int	tmp;

	fd = open(file, O_RDONLY);
	tmp = fd;
	close(fd);
	if (tmp == -1)
		return (1);
	else
		return (0);
}

void	init_var(char *content, t_variable *var)
{
	int	i;
	int	j;
	int	num;

	num = 0;
	j = 0;
	i = 0;
	while (content[i] != '\n')
		i++;
	var->box = content[i - 1];
	var->obs = content[i - 2];
	var->empty = content[i - 3];
	while (j < i - 3)
	{
		num *= 10;
		num += content[j] - '0';
		j++;
	}
	var->line = num;
	var->max_x = 0;
	var->max_y = 0;
	var->max_width = 0;
}

int	ft_get_total_len(char *file)
{
	char	str[10000];
	int		rd;
	int		fd;
	int		len;

	len = 0;
	fd = open(file, O_RDONLY);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, str, 10000);
		len += 10000;
	}
	close(fd);
	return (len);
}

void	ft_get_content(char *content, char *file)
{
	char	str[10001];
	int		rd;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, str, 10000);
		i = 0;
		while (i < rd)
		{
			content[j] = str[i];
			j++;
			i++;
		}
	}
	content[j] = 0;
	close(fd);
}
