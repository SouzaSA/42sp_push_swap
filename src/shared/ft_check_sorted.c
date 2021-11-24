/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:37:32 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/23 11:09:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_sorted_stk_a(t_stack *stk_a)
{
	int	i;
	int	is_sorted;

	is_sorted = 1;
	i = 0;
	if (stk_a->size != stk_a->top + 1)
		is_sorted = 0;
	while (is_sorted && i < stk_a->size - 1)
	{
		if (stk_a->values[i] < stk_a->values[i + 1])
			is_sorted = 0;
		i++;
	}
	return (is_sorted);
}
