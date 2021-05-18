/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/18 15:24:15 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_minmax(t_nd *stack, t_stat *s)
{
	t_nd	*tmp;
	tmp = stack;
	s->min = stack->val;
	s->max = stack->val;
	while (tmp)
	{
		if (tmp->val < s->min)
        	s->min = tmp->val;
    	if (tmp->val > s->max)
        	s->max = tmp->val;
		tmp = tmp->prev;
	}
	
}

void	get_middle(t_nd *stack, long *memory, t_stat *s)
{
	long	anker;
	long	range;
	long	tmp_range;
	t_nd	*tmp;

	tmp = stack;
	get_minmax(stack, s);
	anker = ((s->max - s->min) / 2) + 1;
	range = s->max / 2;
	while (tmp)
	{
		tmp_range = tmp->val - anker;
		if (tmp_range < 0)
			tmp_range *= -1;
		if (tmp_range < range)
		{
			range = tmp_range;
			*memory = tmp->val;
		}
		tmp = tmp->prev;
	}	
}

void	print_args(int  val)
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
	int i;

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