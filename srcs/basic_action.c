/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:52:46 by spark             #+#    #+#             */
/*   Updated: 2021/05/16 22:53:23 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    go_sa(t_nd *a, t_nd *b)
{
    t_nd    *tmp;
    long    tmp_int;
    
    tmp = a;
    if (tmp)
        if (tmp->next)
        {
            while (tmp->next)
                tmp = tmp->next;
            tmp_int = tmp->val;
            tmp->val = tmp->prev->val;
            tmp->prev->val = tmp_int;
        }
    (void)b;
}

void    go_ba(t_nd *a, t_nd *b)
{
    t_nd    *tmp;
    long    tmp_int;
    
    tmp = b;
    if (tmp)
        if (tmp->next)
        {
            while (tmp->next)
                tmp = tmp->next;
            tmp_int = tmp->val;
            tmp->val = tmp->prev->val;
            tmp->prev->val = tmp_int;
        }
    (void)a;
}

void    go_ss(t_nd *a, t_nd *b)
{
    go_sa(a, b);
    go_ba(a, b);
}

void    go_pa(t_nd **a, t_nd **b)
{
    t_nd    *tmp;
    long    tmp_int;

    tmp = *b;
    if (!tmp)
    {
        ft_putstr_fd("Error\n", 2);
        exit (-1);
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp_int = tmp->val;
    if (tmp->prev)
    {
        *b = tmp->prev;
        node_erase(tmp);
    }
    else
    {
        *b = 0;
        node_erase(tmp);
    }
    if (!(*a))
        *a = new_nd_int(tmp_int);
    else
        link_nd_int(a, tmp_int, *a);
}

void    go_pb(t_nd **a, t_nd **b)
{
    t_nd    *tmp;
    long    tmp_int;

    tmp = *a;
    if (!tmp)
    {
        ft_putstr_fd("Error\n", 2);
        exit (-1);
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp_int = tmp->val;
    if (!tmp->prev)
        *a = 0;
    node_erase(tmp);
    if (!(*b))
        *b = new_nd_int(tmp_int);
    else
        link_nd_int(b, tmp_int, *b);
}