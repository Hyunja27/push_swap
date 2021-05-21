/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:28:56 by spark             #+#    #+#             */
/*   Updated: 2021/05/21 16:08:18 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	main_loop(char ***str, char ***av, t_nd **basket_a, t_stat	*info)
{
	int	i;

	i = 1;
	while ((*av)[i])
	{
		*str = ft_split((*av)[i], ' ');
		make_list(*str, basket_a, info);
		i++;
		free_matrix(str);
	}
}

int	main(int ac, char *av[])
{
	char	**str;
	t_nd	*basket_a;
	t_nd	*basket_b;
	t_stat	info;

	init_stat(&info);
	basket_a = 0;
	basket_b = 0;
	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	else
		main_loop(&str, &av, &basket_a, &info);
	lets_roll(&basket_a, &basket_b, &info);
	free_memory(basket_a);
	free_memory(basket_b);
	return (0);
}
