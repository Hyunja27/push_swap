/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:57:54 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 21:09:22 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	if (n >= 'A' && n <= 'Z')
		return (1);
	else if (n >= 'a' && n <= 'z')
		return (2);
	else if (n >= '0' && n <= '9')
		return (1);
	else
		return (0);
	return (0);
}
