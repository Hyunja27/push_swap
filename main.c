/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:28:56 by spark             #+#    #+#             */
/*   Updated: 2021/05/17 17:56:35 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char *av[])
{
    char    **str;
    int     i;
    t_nd    *basket_a;
    t_nd    *basket_b;
    t_stat  info;

    i = 1;
    init_stat(&info);
    basket_a = 0;
    basket_b = 0;
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
    lets_roll(&basket_a, &basket_b, &info);
    free_memory(basket_a);
    free_memory(basket_b);
    return (0);
}
