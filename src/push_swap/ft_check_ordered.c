/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ordered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:37:32 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/15 19:10:27 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_ordered_stk_a(t_stack *stk_a)
{
	int	i;
	int	is_ordered;

	is_ordered = 1;
	i = 0;
	if (stk_a->size != stk_a->top + 1)
		is_ordered = 0;
	while (is_ordered && i < stk_a->size - 1)
	{
		if (stk_a->values[i] < stk_a->values[i + 1])
			is_ordered = 0;
		i++;
	}
	return (is_ordered);
}
