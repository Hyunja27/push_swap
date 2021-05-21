/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:34:18 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 22:20:43 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_loop(t_nd **a, t_nd **b, t_stat *s, int (*flag)[8])
{
	while (++(*flag)[4] < (*flag)[7])
	{
		if (!(*a)->prev)
			break ;
		if ((*a)->val >= s->a_mid)
		{
			if (is_all_ra(*a, s, (*flag)[4], (*flag)[7]))
			{
				real_ra(a, b, s);
				(*flag)[2]++;
			}
			(*flag)[1]++;
		}
		else
		{
			ft_putstr_fd("pb\n", 1);
			go_pb(a, b, s);
			s->count++;
			(*flag)[3]++;
		}
	}
}

void	b_to_a_loop(t_nd **a, t_nd **b, t_stat *s, int (*flag)[8])
{
	while (++(*flag)[4] < (*flag)[7])
	{
		if (!(*b)->prev)
			break ;
		if ((*b)->val < s->b_mid)
		{
			if (is_all_rb(*b, s, (*flag)[4], (*flag)[7]))
			{
				real_rb(a, b, s);
				(*flag)[2]++;
			}
			(*flag)[1]++;
		}
		else
		{
			ft_putstr_fd("pa\n", 1);
			go_pa(a, b, s);
			s->count++;
			(*flag)[3]++;
		}
	}
}

void	quick_a_to_b(t_nd **a, t_nd **b, t_stat *s, int len)
{
	int	flag[8];

	flag_init(&flag, len);
	if (is_aline(a, s))
		return ;
	if ((long)len == s->a_size)
		flag[6] = 0;
	if (len == 1 || len == 0)
		return ;
	get_middle_len(*a, &(s->a_mid), s, len);
	a_to_b_loop(a, b, s, &flag);
	while (flag[6] && (++flag[5] < flag[2]))
	{
		ft_putstr_fd("rra\n", 1);
		s->count++;
		go_rra(a, b, s);
	}
	quick_a_to_b(a, b, s, flag[1]);
	quick_b_to_a(a, b, s, flag[3]);
}

void	quick_b_to_a(t_nd **a, t_nd **b, t_stat *s, int len)
{
	int		flag[8];

	flag_init(&flag, len);
	if ((long)len == s->b_size)
		flag[6] = 0;
	if (len == 0)
		return ;
	get_middle_len(*b, &(s->b_mid), s, len);
	b_to_a_loop(a, b, s, &flag);
	while (flag[6] && (++flag[5] < flag[2]))
	{
		if (is_unaline(b, s))
			return ;
		ft_putstr_fd("rrb\n", 1);
		s->count++;
		go_rrb(a, b, s);
	}
	quick_a_to_b(a, b, s, flag[3]);
	quick_b_to_a(a, b, s, flag[1]);
}

void	lets_roll(t_nd **a, t_nd **b, t_stat *s)
{
	if (s->a_size <= 3)
		small_aline(a, b, s);
	else
		quick_a_to_b(a, b, s, s->a_size);
}
