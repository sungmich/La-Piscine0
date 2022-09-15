/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:03:12 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/15 06:05:52 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_variable
{
	int		line;
	char	empty;
	char	obs;
	char	box;
	int		max_x;
	int		max_y;
	int		max_width;
}	t_variable;

int		ft_file(char *file);
int		ft_check_line_length(char *content);
int		ft_check_line(char *content, t_variable *var);
int		ft_check_var_put(char *content, int i, int j);
int		ft_check_var(char *content);
int		ft_error(char *content, t_variable *var);
int		ft_get_total_len(char *file);
int		**make_our_map(char **map, t_variable *var);
int		ft_check_map(char **map, t_variable *var);
void	ft_sub_bsq(char *content, char **map, int **our_map, t_variable *var);
void	init_var(char *content, t_variable *var);
void	ft_get_content(char *content, char *file);
void	make_map(char *content, char **map);
void	ft_print_map(char **map, t_variable *var);
void	ft_fill_min(char **map, int **our_map, t_variable *var);
void	ft_fill_our_map(char **map, int **our_map, t_variable *var);
void	ft_bsq(t_variable *var, char *file);
void	ft_make_box_map(char **map, t_variable *var);
void	find_max_square(char **map, int **our_map, t_variable *var);
void	ft_free_map(char **map);
void	ft_free_ourmap(int **our_map, char **map);
char	**malloc_map(char *content, t_variable *var);

#endif
