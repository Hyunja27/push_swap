/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/22 19:57:36 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_middle_len(t_nd *stack, long *memory, t_stat *s, int len)
{
	long	anker;
	t_nd	*tmp;
	int		i;

	i = -1;
	tmp = stack;
	get_minmax_len(stack, s, len);
	anker = ((s->max + s->min) / 2);
	if (s->max - s->min == 1)
		*memory = s->max;
	else
		*memory = anker;
}

void	print_args(int val)
{
	int	i;

	i = -1;
	printf("{%d},", val);
}

void	print_list(t_nd *com)
{
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	if (!com)
	{
		ft_putstr_fd("empty string", 2);
		return ;
	}
	tmp_nd = com;
	tmp_nd2 = com;
	print_args(tmp_nd->val);
	printf("\n");
	if (tmp_nd2->prev)
	{
		tmp_nd2 = tmp_nd2->prev;
		tmp_nd = tmp_nd2;
		printf("->");
		print_list(tmp_nd2);
	}
}

void	free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while ((*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	free((*matrix));
}

int		matrix_line_num(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
