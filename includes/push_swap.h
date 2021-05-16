/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:36:56 by spark             #+#    #+#             */
/*   Updated: 2021/05/16 23:01:53 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>

#include <stdlib.h>
#include "libft.h"

typedef struct  s_nd
{
    long            val;
    struct s_nd   *next;
    struct s_nd   *prev;
}               t_nd;

void    make_list(char **str, t_nd **baskt_a);
void	print_args(int  val);
void	print_list(t_nd *com);
void	free_matrix(char ***matrix);
int		matrix_line_num(char **matrix);
void    node_erase(t_nd *tmp);
void    link_nd_int(t_nd **nd, long val, t_nd *head);
t_nd	*new_nd_int(long val);
t_nd	*new_nd(char *val);
void    link_nd(t_nd **nd, char *val, t_nd *head);


void    go_sa(t_nd *a, t_nd *b);
void    go_ba(t_nd *a, t_nd *b);
void    go_ss(t_nd *a, t_nd *b);
void    go_pa(t_nd **a, t_nd **b);
void    go_pb(t_nd **a, t_nd **b);
void    go_ra(t_nd **a, t_nd **b);

#endif