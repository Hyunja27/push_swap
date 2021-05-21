/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:34:18 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 21:18:09 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unaline(t_nd **target, t_stat *s)
{
	t_nd	*tmp;
	long	tmp_val;

	if (!target)
		exit(-1);
	tmp = *target;
	tmp_val = (*target)->val;
	tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->val >= tmp_val)
			return (0);
		tmp_val = tmp->val;
		tmp = tmp->prev;
	}
	return (1);
	(void)s;
}

int	is_aline(t_nd **target, t_stat *s)
{
	t_nd	*tmp;
	long	tmp_val;

	if (!(*target))
		return (0);
	tmp = *target;
	tmp_val = (*target)->val;
	tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->val <= tmp_val)
			return (0);
		tmp_val = tmp->val;
		tmp = tmp->prev;
	}
	if (s->b_size == 0)
		return (1);
	else
		return (0);
	(void)s;
}
