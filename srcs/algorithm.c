/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:34:18 by spark             #+#    #+#             */
/*   Updated: 2021/05/19 16:38:00 by spark            ###   ########.fr       */
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
	get_middle_len(*a, &(s->a_mid), s, len);
	while (++i < len)
	{
		if ((*a)->val <= s->a_mid)
		{
			printf("ra\n");
			go_ra(a, b, s);
			count_r++;
		}
		else
		{
			printf("pb\n");
			go_pb(a, b, s);
			count_p++;
		}
	}
	while (++j < count_r)
	{
		printf("rra\n");
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
	if (len == 0)
		return ;
	get_middle_len(*b, &(s->b_mid), s, len);
	while (++i < len)
	{
		if ((*b)->val > s->b_mid)
		{
			printf("rb\n");
			go_rb(a, b, s);
			count_r++;
		}
		else
		{
			printf("pa\n");
			go_pa(a, b, s);
			count_p++;
		}
	}
	while (++j < count_r)
	{
		printf("rrb\n");
		go_rrb(a, b, s);
	}
	quick_a_to_b(a, b, s, count_p);
	quick_b_to_a(a, b, s, count_r);
}


void    lets_roll(t_nd **a, t_nd **b, t_stat *s)
{
	quick_a_to_b(a, b, s, s->a_size);
}
		// printf("\n//////////////////////\n");
		// print_list(*a);
		// printf("\n\n====================\n\n");
		// print_list(*b);
		// printf("\\\\\\\\\\\\\\\\\\\\\\anker:[%ld],len:[%d] by a to b//\n\n\n\n",s->a_mid,len);
		// sleep(2);