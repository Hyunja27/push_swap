/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/22 19:57:24 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_init(int (*flag)[8], int len)
{
	(*flag)[0] = 0;
	(*flag)[1] = 0;
	(*flag)[2] = 0;
	(*flag)[3] = 0;
	(*flag)[4] = -1;
	(*flag)[5] = -1;
	(*flag)[6] = 1;
	(*flag)[7] = len;
}

int		is_all_num(char ***str)
{
	int	i;
	int	j;

	i = -1;
	while ((*str)[++i])
	{
		j = -1;
		while ((*str)[i][++j])
		{
			if (j == 0)
			{
				if (!ft_isdigit((*str)[i][j]) && (*str)[i][j] != '-')
					return (1);
			}
			else
			{
				if (!ft_isdigit((*str)[i][j]))
					return (1);
			}
		}
	}
	return (0);
}

void	free_memory(t_nd *nd)
{
	t_nd	*tmp1;
	t_nd	*tmp2;

	tmp1 = nd;
	tmp2 = 0;
	while (tmp1)
	{
		if (tmp1->prev)
			tmp2 = tmp1->prev;
		free(tmp1);
		if (tmp2)
			tmp1 = tmp2;
		else
			break ;
		tmp2 = 0;
	}
}

void	init_stat(t_stat *s)
{
	s->a_size = 0;
	s->b_size = 0;
	s->count = 0;
	s->max = 0;
	s->min = 0;
}

void	error_end(void)
{
	ft_putstr_fd("Error", 2);
	exit(1);
}
