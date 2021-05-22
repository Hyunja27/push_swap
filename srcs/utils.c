/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/22 19:57:48 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	real_rb(t_nd **a, t_nd **b, t_stat *s)
{
	ft_putstr_fd("rb\n", 1);
	go_rb(a, b, s);
	s->count++;
}

void	real_ra(t_nd **a, t_nd **b, t_stat *s)
{
	ft_putstr_fd("ra\n", 1);
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
