/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:50:48 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/09 21:58:49 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	ft_check_op(char *op)
{
	int	i;

	i = 0;
	while (op[i])
		i++;
	if (i != 1)
		return (-1);
	if (op[0] == '+')
		return (0);
	else if (op[0] == '-')
		return (1);
	else if (op[0] == '*')
		return (2);
	else if (op[0] == '/')
		return (3);
	else if (op[0] == '%')
		return (4);
	else
		return (-1);
}

int	ft_check_error(int op, int num)
{
	if (num == 0)
	{
		if (op == 3)
		{
			write(1, "Stop : division by zero", 23);
			write(1, "\n", 1);
			return (-1);
		}
		else if (op == 4)
		{
			write(1, "Stop : modulo by zero\n", 21);
			write(1, "\n", 1);
			return (-1);
		}
	}
	return (0);
}

void	ft_func(int num1, int op, int num2, int (*fc[])(int, int))
{
	int		result;
	int		i;

	i = 0;
	result = fc[op](num1, num2);
	ft_putnbr(result);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	num1;
	int	num2;
	int	op;
	int	(*fc[5])(int, int);

	fc[0] = add;
	fc[1] = sub;
	fc[2] = mul;
	fc[3] = div;
	fc[4] = mod;
	if (argc != 4)
		return (0);
	op = ft_check_op(argv[2]);
	if (op == -1)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return (0);
	}
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if (ft_check_error(op, num2) == -1)
		return (0);
	ft_func(num1, op, num2, fc);
	return (0);
}
