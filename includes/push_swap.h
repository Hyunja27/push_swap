/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:36:56 by spark             #+#    #+#             */
/*   Updated: 2021/05/16 18:02:47 by spark            ###   ########.fr       */
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
void	free_matrix(char ***matrix);


#endif