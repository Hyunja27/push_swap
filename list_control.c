/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:59:28 by spark             #+#    #+#             */
/*   Updated: 2021/05/16 18:04:33 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char ***matrix)
{
	int i;

	i = 0;
	while ((*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	free((*matrix));
}

void    link_nd(t_nd *nd, char *val, char (*check)[5000000000])
{
	t_nd	*tmp_nd;
    tmp_nd = malloc(sizeof(t_nd) * 1);
    if (!tmp_nd)
		exit (1);
	tmp_nd->val = ft_atoi(val);
    if (tmp_nd->val < -2147483647 || tmp_nd->val > 2147483648)
    {
        ft_putstr_fd("Error", 2);
        exit(1);
    }
    if (tmp_nd->val < 0)
    {
        if (*check[tmp_nd->val * -1] == 0)
            *check[tmp_nd->val * -1] = 1;
        else if (*check[tmp_nd-> val * -1] == 1)
            *check[tmp_nd->val * -1] = 2;
    }
    else
    {
        if (*check[tmp_nd->val * 2] == 0)
            *check[tmp_nd->val * 2] = 1;
        else if (*check[tmp_nd->val * 2] == 1)
            *check[tmp_nd->val * 2] = 2;
    }
    tmp_nd->prev = nd;
    tmp_nd->prev->next = tmp_nd;
    tmp_nd->next = 0;
}

t_nd	*new_nd(char *val, char (*check)[5000000000])
{
	t_nd	*tmp_nd;

    tmp_nd = malloc(sizeof(t_nd) * 1);
    if (!tmp_nd)
		return (NULL);
	tmp_nd->val = ft_atoi(val);
    if (tmp_nd->val < -2147483647 || tmp_nd->val > 2147483648)
    {
        ft_putstr_fd("Error", 2);
        exit(1);
    }
    if (tmp_nd->val < 0)
    {
        if (*check[tmp_nd->val * -1] == 0)
            *check[tmp_nd->val * -1] = 1;
        else if (*check[tmp_nd-> val * -1] == 1)
            *check[tmp_nd->val * -1] = 2;
    }
    else
    {
        if (*check[tmp_nd->val * 2] == 0)
            *check[tmp_nd->val * 2] = 1;
        else if (*check[tmp_nd->val * 2] == 1)
            *check[tmp_nd->val * 2] = 2;
    }
    tmp_nd->prev = 0;
    tmp_nd->next = 0;
	return (tmp_nd);
}

int		matrix_line_num(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}


void    make_list(char **str, t_nd **baskt_a)
{
    long long       i;
    t_nd            *tmp_nd;
    char            check_same[5000000000];

    i = 0;
    ft_memset(check_same, 0, 5000000000);
    tmp_nd = *baskt_a;
    if (tmp_nd != NULL)
        while (tmp_nd->next)
            tmp_nd = tmp_nd->next;
    else
        *baskt_a = new_nd(str[i++], &check_same); 
    while (str[i])
        link_nd(tmp_nd, str[i++], &check_same);
    i = 0;
    while (i < 5000000000)
        if (check_same[i] == 2)
        {
            ft_putstr_fd("Error", 2);
            exit(1);
        }
}


// t_nd	*new_nd(char *name)
// {
// 	t_nd	*tmp_nd;

// 	tmp_nd = malloc(sizeof(t_nd) * 1);
// 	if (!tmp_nd)
// 		return (NULL);
// 	if (name != NULL)
// 	{
// 		tmp_nd->args = (char **)malloc(sizeof(char *) * 2);
// 		if (!tmp_nd->args)
// 			return (NULL);
// 		tmp_nd->args[0] = ft_strdup(name);
// 		tmp_nd->args[1] = 0;
// 	}
// 	tmp_nd->child = 0;
// 	tmp_nd->sible = 0;
// 	tmp_nd->prev = 0;
// 	tmp_nd->type = -1;
// 	tmp_nd->re.rdrt_type = 0;
// 	tmp_nd->re.rdrt_fd = 0;
// 	tmp_nd->re.rdrt_name = 0;
// 	tmp_nd->re.rdrt_in_type = 0;
// 	tmp_nd->re.rdrt_in_fd = 0;
// 	tmp_nd->re.rdrt_in_name = 0;
// 	return (tmp_nd);
// }