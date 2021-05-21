/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:52:06 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 21:17:00 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_str_2(t_nd **a, t_nd **b, t_stat *s, char *str)
{
	if (!ft_strcmp("rr", str))
		go_rr(a, b, s);
	else if (!ft_strcmp("rra", str))
		go_rra(a, b, s);
	else if (!ft_strcmp("rrb", str))
		go_rrb(a, b, s);
	else if (!ft_strcmp("rrr", str))
		go_rrr(a, b, s);
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(-1);
	}
}

void	check_str(t_nd **a, t_nd **b, t_stat *s, char *str)
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
	else
		check_str_2(a, b, s, str);
}

static void	main_loop(char ***str, char ***av, t_nd **basket_a, t_stat *info)
{
	int	i;

	i = 1;
	while ((*av)[i])
	{
		*str = ft_split((*av)[i], ' ');
		make_list(*str, basket_a, info);
		if (is_all_num(str))
		{
			ft_putstr_fd("Error\n", 1);
			exit (-1);
		}
		i++;
		free_matrix(str);
	}
}

static int	main_loop_2(char *buf, t_nd **a, t_nd **b, t_stat *info)
{
	int	i;

	i = 0;
	if (!i)
	{
		while (0 < get_next_line(0, &buf))
		{
			if (!ft_strcmp(buf, "\n") || !ft_strcmp(buf, ""))
				break ;
			check_str(a, b, info, buf);
			if (info->a_size == 0)
				break ;
		}
	}
	i = is_aline(a, info);
	if (i == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (1);
}

int		main(int ac, char *av[])
{
	char	*buf;
	char	**str;
	t_nd	*basket_a;
	t_nd	*basket_b;
	t_stat	info;

	init_stat(&info);
	buf = ft_calloc(sizeof(char), 5000);
	basket_a = 0;
	basket_b = 0;
	if (ac == 1)
		return (-1);
	else
		main_loop(&str, &av, &basket_a, &info);
	while (!main_loop_2(buf, &basket_a, &basket_b, &info))
		;
	free_memory(basket_a);
	free_memory(basket_b);
	return (0);
}
