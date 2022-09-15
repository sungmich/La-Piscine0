/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:37:45 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/15 06:05:56 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_sub_sub_bsq(char *content, char **map, t_variable *var)
{
	make_map(content, map);
	if (ft_check_map(map, var))
	{
		free(content);
		ft_free_map(map);
		write(1, "map error\n", 10);
		return (1);
	}
	return (0);
}

void	ft_sub_bsq(char *content, char **map, int **our_map, t_variable *var)
{
	find_max_square(map, our_map, var);
	ft_make_box_map(map, var);
	ft_print_map(map, var);
	ft_free_ourmap(our_map, map);
	ft_free_map(map);
	free(content);
}

void	ft_bsq(t_variable *var, char *file)
{
	char	**map;
	int		**our_map;
	int		total_len;
	char	*content;

	if (ft_file(file))
	{
		write(1, "map error\n", 10);
		return ;
	}
	total_len = ft_get_total_len(file);
	content = (char *)malloc(sizeof(char) * total_len + 1);
	ft_get_content(content, file);
	if (ft_error(content, var))
	{
		free(content);
		write(1, "map error\n", 10);
		return ;
	}
	map = malloc_map(content, var);
	if (ft_sub_sub_bsq(content, map, var) == 1)
		return ;
	our_map = make_our_map(map, var);
	ft_sub_bsq(content, map, our_map, var);
}

int	main(int ac, char **av)
{
	int			i;
	t_variable	var;
	int			fd;
	char		ch;

	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
			ft_bsq(&var, av[i]);
	}
	else
	{
		fd = open("stdin.txt", O_CREAT | O_TRUNC | O_RDWR, 0777);
		while (read(0, &ch, 1))
			write(fd, &ch, 1);
		ft_bsq(&var, "stdin.txt");
		close(fd);
	}
	return (0);
}
