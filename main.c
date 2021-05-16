/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:28:56 by spark             #+#    #+#             */
/*   Updated: 2021/05/16 21:04:40 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char *av[])
{
    char    **str;
    int     i;
    t_nd    *basket_a;

    i = 1;
    basket_a = 0;
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
            make_list(str, &basket_a);
            i++;
            free_matrix(&str);
        }
    }
    print_list(basket_a);
    return (0);
}

        // while(str[++i])
        // {
        //     write(1, str[i], ft_strlen(str[i]));
        //     write(1, "\n", 1);
        // }