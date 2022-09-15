/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmich <sungmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:23:56 by sungmich          #+#    #+#             */
/*   Updated: 2022/09/07 17:06:49 by sungmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check(char c, char *charset)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (-1);
}

int	ft_word_cnt_malloc(char *str, char *charset)
{
	int	i;
	int	word_cnt;

	word_cnt = 0;
	i = 0;
	while (str[i])
	{
		while (ft_check(str[i], charset) == 1 && str[i])
			i++;
		if (!str[i])
			break ;
		while (ft_check(str[i], charset) == -1 && str[i])
			i++;
		word_cnt++;
	}
	return (word_cnt);
}

void	ft_word_line_malloc(char	*str, char	*charset, char	**strs)
{
	int	i;
	int	cnt;
	int	j;

	i = 0;
	cnt = 0;
	j = 0;
	while (str[i])
	{
		while (ft_check(str[i], charset) == 1 && str[i])
			i++;
		if (!str[i])
			break ;
		while (ft_check(str[i], charset) == -1 && str[i])
		{
			i++;
			cnt++;
		}
		strs[j++] = (char *)malloc(sizeof(char) * (cnt + 1));
		cnt = 0;
	}
}

void	ft_copy(char *str, char *charset, char **strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (ft_check(str[i], charset) == 1 && str[i])
			i++;
		if (!str[i])
		{
			strs[j] = 0;
			break ;
		}
		while (ft_check(str[i], charset) == -1 && str[i])
		{
			strs[j][k] = str[i++];
			k++;
		}
		strs[j++][k] = '\0';
		k = 0;
	}
	strs[j] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		word_cnt;

	word_cnt = 0;
	word_cnt = ft_word_cnt_malloc(str, charset);
	strs = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	ft_word_line_malloc(str, charset, strs);
	ft_copy(str, charset, strs);
	return (strs);
}
