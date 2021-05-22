/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/22 19:56:47 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	link_nd_int(t_nd **nd, long val, t_nd *head, t_stat *s)
{
	t_nd	*tmp_nd;
	t_nd	*tmp;

	tmp = head;
	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		exit(1);
	tmp_nd->val = val;
	while (tmp)
	{
		if (tmp->val == tmp_nd->val)
			error_end();
		else
			tmp = tmp->next;
	}
	if (tmp_nd->val < s->min)
		s->min = tmp_nd->val;
	if (tmp_nd->val > s->max)
		s->max = tmp_nd->val;
	tmp_nd->prev = *nd;
	if (tmp_nd->prev)
		tmp_nd->prev->next = tmp_nd;
	tmp_nd->next = 0;
}

void	link_nd(t_nd **nd, char *val, t_nd *head, t_stat *s)
{
	t_nd	*tmp_nd;
	t_nd	*tmp;

	tmp = head;
	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		exit(1);
	tmp_nd->val = ft_atol(val);
	while (tmp)
	{
		if (tmp->val == tmp_nd->val)
			error_end();
		else
			tmp = tmp->prev;
	}
	if (tmp_nd->val < -2147483648 || tmp_nd->val > 2147483647)
		error_end();
	if (tmp_nd->val < s->min)
		s->min = tmp_nd->val;
	if (tmp_nd->val > s->max)
		s->max = tmp_nd->val;
	tmp_nd->next = *nd;
	tmp_nd->next->prev = tmp_nd;
	tmp_nd->prev = 0;
}

t_nd	*new_nd(char *val, t_stat *s)
{
	t_nd	*tmp_nd;

	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		return (NULL);
	tmp_nd->val = ft_atol(val);
	if (tmp_nd->val < -2147483648 || tmp_nd->val > 2147483647)
		error_end();
	tmp_nd->prev = 0;
	tmp_nd->next = 0;
	return (tmp_nd);
	(void)s;
}
