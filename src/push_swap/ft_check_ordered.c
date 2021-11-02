/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ordered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:37:32 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/02 19:40:06 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_ordered(int *values, int size)
{
	int	i;
	int	is_ordered;

	is_ordered = 1;
	i = 0;
	while (i < size - 1)
	{
		if (values[i] > values[i + 1])
			is_ordered = 0;
		i++;
	}
	return (is_ordered);
}
