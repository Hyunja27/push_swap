/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:52:06 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 13:05:48 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_str(t_nd **a, t_nd **b, t_stat *s, char *str)
{
	if (!ft_strcmp("sa", str))
		go_sa(*a, *b, s);
	else if (!ft_strcmp("sb", str))
		go_sb(*a, *b, s);
	else if (!ft_strcmp("ss", str))
        go_ss(*a, *b, s); 
	else if (!ft_strcmp("pa", str))
        go_pa(a, b, s); 
	else if (!ft_strcmp("pb", str))
		go_pb(a, b, s);
	else if (!ft_strcmp("ra", str))
		go_ra(a, b, s);
	else if (!ft_strcmp("rb", str))
		go_rb(a, b, s);
	else if (!ft_strcmp("rr", str))
		go_rr(a, b, s);
	else if (!ft_strcmp("rra", str))
		go_rra(a, b, s);
	else if (!ft_strcmp("rrb", str))
		go_rrb(a, b, s);
	else if (!ft_strcmp("rrr", str))
		go_rrr(a, b, s);
}

int		main(int ac, char *av[])
{
	char    *buf;
	char    **str;
	int     i;
	t_nd    *basket_a;
	t_nd    *basket_b;
	t_stat  info;

	i = 1;
	init_stat(&info);
	basket_a = 0;
	basket_b = 0;
	buf = (char*)malloc(sizeof(char) * 5000);
	ft_memset(buf, 0, 5000);
	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	else
	{
		while (av[i])
		{
			str = ft_split(av[i], ' ');
			make_list(str, &basket_a, &info);
			i++;
			free_matrix(&str);
		}
	}
	while (0 < get_next_line(0, &buf))
	{
		if (!ft_strcmp(buf, "\n") || !ft_strcmp(buf, ""))
		{
			if (!i)
				ft_putstr_fd("KO", 1);
			break;
		}
		check_str(&basket_a, &basket_b, &info, buf);
		i = is_aline(&basket_a, &info);
		if (i)
			break;
	}
	if (i)
		ft_putstr_fd("OK", 1);
	else 
		ft_putstr_fd("KO", 1);
	free(buf);
	return (0);
}