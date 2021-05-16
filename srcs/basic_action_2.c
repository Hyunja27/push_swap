/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_action_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:52:46 by spark             #+#    #+#             */
/*   Updated: 2021/05/16 23:25:14 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    go_ra(t_nd **a, t_nd **b)
{
    t_nd    *tmp;
    t_nd    *tmp_prev;
    t_nd    *new_head;
    long    tmp_int;
    
    tmp = *a;
    if (tmp)
        if (tmp->next)
        {
            while (tmp->next)
                tmp = tmp->next;
            tmp_int = tmp->val;
            tmp_prev = tmp->prev;
            node_erase(tmp);
            new_head = new_nd_int(tmp_int);
            new_head->next = *a;
            (*a)->prev = new_head;
            while ((*a)->prev)
                *a = (*a)->prev;
        }
    (void)b;
}

void    go_rb(t_nd **a, t_nd **b)
{
    t_nd    *tmp;
    t_nd    *tmp_prev;
    t_nd    *new_head;
    long    tmp_int;
    
    tmp = *b;
    if (tmp)
        if (tmp->next)
        {
            while (tmp->next)
                tmp = tmp->next;
            tmp_int = tmp->val;
            tmp_prev = tmp->prev;
            node_erase(tmp);
            new_head = new_nd_int(tmp_int);
            new_head->next = *b;
            (*b)->prev = new_head;
            while ((*b)->prev)
                *b = (*b)->prev;
        }
    (void)a;
}