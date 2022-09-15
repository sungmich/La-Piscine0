/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:34:01 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/10 11:36:02 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_H
# define FT_H

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
int		ft_check_op(char *op);
int		ft_check_error(int op, int num);
void	ft_func(int num1, int op, int num2, int (*fc[])(int, int));

#endif
