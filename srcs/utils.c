/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 17:38:34 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	real_rb(t_nd **a, t_nd **b, t_stat *s)
{
	printf("rb\n");
	go_rb(a, b, s);
	s->count++;
}

void	real_ra(t_nd **a, t_nd **b, t_stat *s)
{
	printf("ra\n");
	go_ra(a, b, s);
	s->count++;
}

int		is_all_ra(t_nd *target, t_stat *s, int i, int len)
{
	int	j;

	j = i;
	while (j < len)
	{
		if ((target->val < s->a_mid))
			return (1);
		target = target->prev;
		j++;
	}
	return (0);
}

int		is_all_rb(t_nd *target, t_stat *s, int i, int len)
{
	int	j;

	j = i;
	while (j < len)
	{
		if ((target->val >= s->b_mid))
			return (1);
		target = target->prev;
		j++;
	}
	return (0);
}

void	get_minmax_len(t_nd *stack, t_stat *s, int len)
{
	t_nd	*tmp;
	int		i;

	tmp = stack;
	i = -1;
	s->min = stack->val;
	s->max = stack->val;
	while (++i < len)
	{
		if (tmp->val < s->min)
        	s->min = tmp->val;
    	if (tmp->val > s->max)
        	s->max = tmp->val;
		tmp = tmp->prev;
	}
}

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