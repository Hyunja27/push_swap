/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_control_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/22 00:38:39 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_erase(t_nd *tmp)
{
	if (tmp->next)
		tmp->next->prev = 0;
	else if (tmp->prev)
		tmp->prev->next = 0;
	free(tmp);
}

t_nd	*new_nd_int(long val, t_stat *s)
{
	t_nd	*tmp_nd;

	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		return (NULL);
	tmp_nd->val = val;
	tmp_nd->prev = 0;
	tmp_nd->next = 0;
	return (tmp_nd);
	(void)s;
}

void	make_list(char **str, t_nd **baskt_a, t_stat *s)
{
	long long	i;
	t_nd		*tmp_nd;

	i = 0;
	tmp_nd = *baskt_a;
	if (tmp_nd != NULL)
		while (tmp_nd->prev)
			tmp_nd = tmp_nd->prev;
	else
	{
		*baskt_a = new_nd(str[i++], s);
		tmp_nd = *baskt_a;
		s->a_size++;
	}
	while (str[i])
	{
		link_nd(&tmp_nd, str[i++], *baskt_a, s);
		if (tmp_nd->prev)
			tmp_nd = tmp_nd->prev;
		s->a_size++;
	}
	i = 0;
}
