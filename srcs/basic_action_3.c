/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_action_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:52:46 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 20:25:31 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_rra(t_nd **a, t_nd **b, t_stat *s)
{
	t_nd	*tmp;
	t_nd	*new_head;
	long	tmp_int;

	tmp = *a;
	if (tmp)
	{
		if (tmp->prev)
		{
			while (tmp->prev)
				tmp = tmp->prev;
			tmp_int = tmp->val;
			node_erase(tmp);
			new_head = new_nd_int(tmp_int, s);
			(*a)->next = new_head;
			new_head->prev = *a;
			*a = new_head;
		}
	}
	(void)b;
}

void	go_rrb(t_nd **a, t_nd **b, t_stat *s)
{
	t_nd	*tmp;
	t_nd	*new_head;
	long	tmp_int;

	tmp = *b;
	if (tmp)
	{
		if (tmp->prev)
		{
			while (tmp->prev)
				tmp = tmp->prev;
			tmp_int = tmp->val;
			node_erase(tmp);
			new_head = new_nd_int(tmp_int, s);
			(*b)->next = new_head;
			new_head->prev = *b;
			*b = new_head;
		}
	}
	(void)a;
}

void	go_rrr(t_nd **a, t_nd **b, t_stat *s)
{
	go_rra(a, b, s);
	go_rrb(a, b, s);
}
