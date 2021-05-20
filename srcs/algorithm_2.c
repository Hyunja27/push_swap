/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:34:18 by spark             #+#    #+#             */
/*   Updated: 2021/05/20 17:57:45 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    small_aline(t_nd **a, t_nd **b, t_stat *s)
{
	
}

int		is_aline(t_nd **target, t_stat *s)
{
	t_nd *tmp;
	long tmp_val;

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
}

void    small_aline(t_nd **a, t_nd **b, t_stat *s)
{
	if (is_aline(a, s))
		exit (1);
	else
		reroll(a, b, s);
}
		// printf("\n//////////////////////\n");
		// print_list(*a);
		// printf("\n\n====================\n\n");
		// print_list(*b);
		// printf("\\\\\\\\\\\\\\\\\\\\\\anker:[%ld],len:[%d] by a to b//\n\n\n\n",s->a_mid,len);
		// sleep(2);