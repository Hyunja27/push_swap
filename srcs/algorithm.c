/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:34:18 by spark             #+#    #+#             */
/*   Updated: 2021/05/17 19:26:25 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    lets_roll(t_nd **a, t_nd **b, t_stat *s)
{
    t_nd *tmp;

    while (*a != NULL)
    {
        if ((*a)->val != s->min)
        {
            go_ra(a, b, s);
            ft_putstr_fd("ra\n",1);
        }
        else
        {
            go_pb(a, b, s);
            ft_putstr_fd("pb\n",1);
            tmp = *a;
            s->min = (*a)->val;
            while (tmp)
            {
                if (tmp->val < s->min)
                    s->min = tmp->val;
                tmp = tmp->prev;
            }
        }
    }
    while (*b != NULL)
    {
        go_pa(a, b, s);
        ft_putstr_fd("pa\n",1);
    }
}