/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:34:18 by spark             #+#    #+#             */
/*   Updated: 2021/05/22 19:57:08 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reroll(t_nd **a, t_nd **b, t_stat *s)
{
	get_minmax_len(*a, s, s->a_size);
	while (s->a_size > 3)
	{
		if ((*a)->val == s->min)
		{
			go_pb(a, b, s);
			ft_putstr_fd("pb\n", 1);
			s->count++;
			get_minmax_len(*a, s, s->a_size);
		}
		else
		{
			go_ra(a, b, s);
			ft_putstr_fd("ra\n", 1);
			s->count++;
		}
	}
	reroll_3(a, b, s);
	while (s->b_size > 0)
	{
		go_pa(a, b, s);
		ft_putstr_fd("pa\n", 1);
		s->count++;
	}
}

void	reroll_2(t_nd **a, t_nd **b, t_stat *s)
{
	get_minmax_len(*a, s, 2);
	if (!is_aline(a, s))
	{
		go_sa(*a, *b, s);
		ft_putstr_fd("sa\n", 1);
		s->count++;
	}
}

void	reroll_3(t_nd **a, t_nd **b, t_stat *s)
{
	t_nd	*tmp;

	get_minmax_len(*a, s, 3);
	while (!is_aline(a, s))
	{
		tmp = *a;
		while (tmp->prev)
			tmp = tmp->prev;
		if (tmp->val == s->max)
		{
			if (is_aline(a, s))
				break ;
			go_sa(*a, *b, s);
			ft_putstr_fd("sa\n", 1);
			s->count++;
		}
		else
		{
			go_ra(a, b, s);
			ft_putstr_fd("ra\n", 1);
			s->count++;
			if (is_aline(a, s))
				break ;
		}
	}
}

void	small_aline(t_nd **a, t_nd **b, t_stat *s)
{
	if (is_aline(a, s))
		exit(1);
	else if (s->a_size == 3)
		reroll_3(a, b, s);
	else if (s->a_size == 2)
		reroll_2(a, b, s);
	else
		reroll(a, b, s);
}
