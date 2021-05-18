/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:34:18 by spark             #+#    #+#             */
/*   Updated: 2021/05/18 15:09:09 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    quick_a_to_b(t_nd **a, t_nd **b, t_stat *s, int len)
{
    int     count_r;
    int     count_p;
    int     i;
    int     j;

    count_r = 0;
    count_p = 0;
    i = -1;
    j = -1;
    if (len == 1)
        return ;
    get_middle(*a, &(s->a_mid), s);
    while (++i < len)
    {
        if ((*a)->val > s->a_mid)
        {
            go_ra(a, b, s);
            count_r++;
        }
        else
        {
            printf("\n-> %ld", (*a)->val);
            go_pb(a, b, s);
            count_p++;
        }
    }
    while (++j < count_r)
    {
        go_rra(a, b, s);
    }
    quick_a_to_b(a, b, s, count_r);
    quick_b_to_a(a, b, s, count_p);
}

void    quick_b_to_a(t_nd **a, t_nd **b, t_stat *s, int len)
{
    int     count_r;
    int     count_p;
    int     i;
    int     j;

    count_r = 0;
    count_p = 0;
    i = -1;
    j = -1;
    if (len == 1)
    {
        go_pa(a, b, s);
        return ;
    }
    get_middle(*b, &(s->b_mid), s);
    while (++i < len)
    {
        if ((*b)->val > s->b_mid)
        {
            go_rb(a, b, s);
            count_r++;
        }
        else
        {
            go_pa(a, b, s);
            count_p++;
        } 
    }
    while (++j < count_r)
        go_rrb(a, b, s); 
    quick_a_to_b(a, b, s, count_p);
    quick_b_to_a(a, b, s, len);
}


void    lets_roll(t_nd **a, t_nd **b, t_stat *s)
{
    quick_a_to_b(a, b, s, (int)s->a_size);
}

// void    lets_roll(t_nd **a, t_nd **b, t_stat *s)
// {
//     t_nd *tmp;

//     while (*a != NULL)
//     {
//         if ((*a)->val != s->min)
//         {
//             go_ra(a, b, s);
//             ft_putstr_fd("ra\n",1);
//         }
//         else
//         {
//             go_pb(a, b, s);
//             ft_putstr_fd("pb\n",1);
//             tmp = *a;
//             s->min = (*a)->val;
//             while (tmp)
//             {
//                 if (tmp->val < s->min)
//                     s->min = tmp->val;
//                 tmp = tmp->prev;
//             }
//         }
//     }
//     while (*b != NULL)
//     {
//         go_pa(a, b, s);
//         ft_putstr_fd("pa\n",1);
//     }
// }