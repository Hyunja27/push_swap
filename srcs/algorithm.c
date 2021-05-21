/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:34:18 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 20:16:12 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_a_to_b(t_nd **a, t_nd **b, t_stat *s, int len)
{
	int	count_r;
	int	count_rr;
	int	count_p;
	int	i;
	int	j;
	int	roll_need;

	count_r = 0;
	count_rr = 0;
	count_p = 0;
	roll_need = 1;
	if (is_aline(a, s))
		return ;
	if ((long)len == s->a_size)
		roll_need = 0;
	i = -1;
	j = -1;
	if (len == 1 || len == 0)
		return ;
	get_middle_len(*a, &(s->a_mid), s, len);
	while (++i < len)
	{
		if (!(*a)->prev)
			break ;
		if ((*a)->val >= s->a_mid)
		{
			if (is_all_ra(*a, s, i, len))
			{
				real_ra(a, b, s);
				count_rr++;
			}
			count_r++;
		}
		else
		{
			printf("pb\n");
			go_pb(a, b, s);
			s->count++;
			count_p++;
		}
	}
	while (roll_need && (++j < count_rr))
	{
		printf("rra\n");
		s->count++;
		go_rra(a, b, s);
	}
	quick_a_to_b(a, b, s, count_r);
	quick_b_to_a(a, b, s, count_p);
}


void	quick_b_to_a(t_nd **a, t_nd **b, t_stat *s, int len)
{
	int		count_r;
	int		count_rr;
	int		count_p;
	int		i;
	int		j;
	int		roll_need;

	count_r = 0;
	count_rr = 0;
	count_p = 0;
	roll_need = 1;
	if ((long)len == s->b_size)
		roll_need = 0;
	i = -1;
	j = -1;
	if (len == 0)
		return ;
	get_middle_len(*b, &(s->b_mid), s, len);
	while (++i < len)
	{
		if ((*b)->val < s->b_mid)
		{
			if (is_all_rb(*b, s, i, len))
			{
				real_rb(a, b, s);
				count_rr++;
			}	
			count_r++;
		}
		else
		{
			printf("pa\n");
			go_pa(a, b, s);
			s->count++;
			count_p++;
		}
	}
	while (roll_need && (++j < count_rr))
	{
		if (is_unaline(b, s))
			return ;
		printf("rrb\n");
		s->count++;
		go_rrb(a, b, s);
	}
	quick_a_to_b(a, b, s, count_p);
	quick_b_to_a(a, b, s, count_r);
}


void    lets_roll(t_nd **a, t_nd **b, t_stat *s)
{
	if (s->a_size <= 3)
		small_aline(a, b, s);
	else
		quick_a_to_b(a, b, s, s->a_size);
}
