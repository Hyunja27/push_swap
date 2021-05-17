/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/17 15:46:32 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    node_erase(t_nd *tmp)
{
    if (tmp->next)
        tmp->next->prev = 0;
    else if (tmp->prev)
        tmp->prev->next = 0;
    free(tmp);
}

void    link_nd_int(t_nd **nd, long val, t_nd *head, t_stat *s)
{
	t_nd	*tmp_nd;
    t_nd	*tmp;

    tmp = head;
    tmp_nd = malloc(sizeof(t_nd) * 1);
    if (!tmp_nd)
		exit (1);
	tmp_nd->val = val;
    while (tmp)
    {
        if (tmp->val == tmp_nd->val)
        {
            ft_putstr_fd("Error", 2);
            exit(1);
        }
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

void    link_nd(t_nd **nd, char *val, t_nd *head, t_stat *s)
{
	t_nd	*tmp_nd;
    t_nd	*tmp;

    tmp = head;
    tmp_nd = malloc(sizeof(t_nd) * 1);
    if (!tmp_nd)
		exit (1);
	tmp_nd->val = ft_atol(val);
    while (tmp)
    {
        if (tmp->val == tmp_nd->val)
        {
            ft_putstr_fd("Error", 2);
            exit(1);
        }
        else
            tmp = tmp->prev;
    }
    if (tmp_nd->val < -2147483648 || tmp_nd->val > 2147483647)
    {
        ft_putstr_fd("Error", 2);
        exit(1);
    }
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
    {
        ft_putstr_fd("Error", 2);
        exit(1);
    }
    if (tmp_nd->val < s->min)
        s->min = tmp_nd->val;
    if (tmp_nd->val > s->max)
        s->max = tmp_nd->val;
    tmp_nd->prev = 0;
    tmp_nd->next = 0;
	return (tmp_nd);
}

t_nd	*new_nd_int(long val, t_stat *s)
{
	t_nd	*tmp_nd;

    tmp_nd = malloc(sizeof(t_nd) * 1);
    if (!tmp_nd)
		return (NULL);
	tmp_nd->val = val;
    if (tmp_nd->val < s->min)
        s->min = tmp_nd->val;
    if (tmp_nd->val > s->max)
        s->max = tmp_nd->val;
    tmp_nd->prev = 0;
    tmp_nd->next = 0;
	return (tmp_nd);
}

void    make_list(char **str, t_nd **baskt_a, t_stat *s)
{
    long long       i;
    t_nd            *tmp_nd;
    

    i = 0;
    tmp_nd = *baskt_a;
    if (tmp_nd != NULL)
        while (tmp_nd->prev)
            tmp_nd = tmp_nd->prev;
    else
    {
        *baskt_a = new_nd(str[i++], s);
        tmp_nd = *baskt_a;
    }
    while (str[i])
    {
        link_nd(&tmp_nd, str[i++], *baskt_a, s);
        if (tmp_nd->prev)
            tmp_nd = tmp_nd->prev;
    }
    i = 0;
}