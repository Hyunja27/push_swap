/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:52:46 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 20:42:26 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_sa(t_nd *a, t_nd *b, t_stat *s)
{
	t_nd	*tmp;
	long	tmp_int;

	tmp = a;
	if (tmp)
	{
		if (tmp->prev)
		{
			tmp_int = tmp->val;
			tmp->val = tmp->prev->val;
			tmp->prev->val = tmp_int;
		}
	}
	(void)b;
	(void)s;
}

void	go_sb(t_nd *a, t_nd *b, t_stat *s)
{
	t_nd	*tmp;
	long	tmp_int;

	tmp = b;
	if (tmp)
	{
		if (tmp->prev)
		{
			tmp_int = tmp->val;
			tmp->val = tmp->prev->val;
			tmp->prev->val = tmp_int;
		}
	}
	(void)a;
	(void)s;
}

void	go_ss(t_nd *a, t_nd *b, t_stat *s)
{
	go_sa(a, b, s);
	go_sb(a, b, s);
}

void	go_pa(t_nd **a, t_nd **b, t_stat *s)
{
	t_nd	*tmp;
	long	tmp_int;

	tmp = *b;
	if (!tmp)
		return ;
	tmp_int = tmp->val;
	if (!tmp->prev)
		*b = 0;
	else
		*b = tmp->prev;
	node_erase(tmp);
	if (!(*a))
		*a = new_nd_int(tmp_int, s);
	else
	{
		link_nd_int(a, tmp_int, *a, s);
		*a = (*a)->next;
	}
	s->a_size++;
	s->b_size--;
}

void	go_pb(t_nd **a, t_nd **b, t_stat *s)
{
	t_nd	*tmp;
	long	tmp_int;

	tmp = *a;
	if (!tmp)
		return ;
	tmp_int = tmp->val;
	if (!tmp->prev)
		*a = 0;
	else
		*a = tmp->prev;
	node_erase(tmp);
	if (!(*b))
		*b = new_nd_int(tmp_int, s);
	else
	{
		link_nd_int(b, tmp_int, *b, s);
		*b = (*b)->next;
	}
	s->b_size++;
	s->a_size--;
}
