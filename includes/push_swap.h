/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:36:56 by spark             #+#    #+#             */
/*   Updated: 2021/05/19 17:53:56 by spark            ###   ########.fr       */
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

typedef struct  s_stat
{
    long            max;
    long            min;
    long            a_size;
    long            b_size;
    long            a_mid;
    long            b_mid;    
    long            count;
}               t_stat;

void    make_list(char **str, t_nd **baskt_a, t_stat *s);
void	print_args(int  val);
void	print_list(t_nd *com);
void	free_matrix(char ***matrix);
int		matrix_line_num(char **matrix);
void    node_erase(t_nd *tmp);
void    link_nd_int(t_nd **nd, long val, t_nd *head, t_stat *s);
t_nd	*new_nd_int(long val, t_stat *s);
t_nd	*new_nd(char *val, t_stat *s);
void    link_nd(t_nd **nd, char *val, t_nd *head, t_stat *s);
void	free_memory(t_nd *nd);
void	init_stat(t_stat *s);
void    lets_roll(t_nd **a, t_nd **b, t_stat *s);
void	get_middle_len(t_nd *stack, long *memory, t_stat *s, int len);
void    quick_a_to_b(t_nd **a, t_nd **b, t_stat *s, int len);
void    quick_b_to_a(t_nd **a, t_nd **b, t_stat *s, int len);
void	real_rb(t_nd **a, t_nd **b, t_stat *s);
void	real_ra(t_nd **a, t_nd **b, t_stat *s);
int		is_all_ra(t_nd *target, t_stat *s, int i, int len);
int		is_all_rb(t_nd *target, t_stat *s, int i, int len);


void    go_sa(t_nd *a, t_nd *b, t_stat *s);
void    go_sb(t_nd *a, t_nd *b, t_stat *s);
void    go_ss(t_nd *a, t_nd *b, t_stat *s);
void    go_pa(t_nd **a, t_nd **b, t_stat *s);
void    go_pb(t_nd **a, t_nd **b, t_stat *s);
void    go_ra(t_nd **a, t_nd **b, t_stat *s);
void    go_rb(t_nd **a, t_nd **b, t_stat *s);
void    go_rr(t_nd **a, t_nd **b, t_stat *s);
void    go_rra(t_nd **a, t_nd **b, t_stat *s);
void    go_rrb(t_nd **a, t_nd **b, t_stat *s);
void    go_rrr(t_nd **a, t_nd **b, t_stat *s);

#endif