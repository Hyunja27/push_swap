/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_action_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:52:46 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 20:22:52 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_ra(t_nd **a, t_nd **b, t_stat *s)
{
	t_nd	*tmp;
	t_nd	*tmp_prev;
	t_nd	*new_head;
	long	tmp_int;

	tmp = *a;
	if (tmp)
	{
		if (tmp->prev)
		{
			tmp_int = tmp->val;
			tmp_prev = tmp->prev;
			node_erase(tmp);
			*a = tmp_prev;
			new_head = new_nd_int(tmp_int, s);
			while (tmp_prev->prev)
				tmp_prev = tmp_prev->prev;
			new_head->next = tmp_prev;
			tmp_prev->prev = new_head;
		}
	}
	(void)b;
}

void	go_rb(t_nd **a, t_nd **b, t_stat *s)
{
	t_nd	*tmp;
	t_nd	*tmp_prev;
	t_nd	*new_head;
	long	tmp_int;

	tmp = *b;
	if (tmp)
	{
		if (tmp->prev)
		{
			tmp_int = tmp->val;
			tmp_prev = tmp->prev;
			node_erase(tmp);
			*b = tmp_prev;
			new_head = new_nd_int(tmp_int, s);
			while (tmp_prev->prev)
				tmp_prev = tmp_prev->prev;
			new_head->next = tmp_prev;
			tmp_prev->prev = new_head;
		}
	}
	(void)a;
}

void	go_rr(t_nd **a, t_nd **b, t_stat *s)
{
	go_ra(a, b, s);
	go_rb(a, b, s);
}
