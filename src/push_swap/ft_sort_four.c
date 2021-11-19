/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:54 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 10:48:40 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_four(t_stack *stk_a, t_stack *stk_b, int len)
{
	int	min_idx;
	int	min_val;

	min_idx = ft_smallest_int_idx(stk_a->values, len);
	min_val = stk_a->values[min_idx];
	if (min_idx >= len / 2)
	{
		while (min_val != stk_a->values[stk_a->top])
			ft_rotate(stk_a, 'a');
	}
	else
	{
		while (min_val != stk_a->values[stk_a->top])
			ft_reverse_rotate(stk_a, 'a');
	}
	if(!ft_is_ordered_stk_a(stk_a))
	{
		ft_push(stk_a, stk_b, 'b');
		ft_sort_three(stk_a, 3);
		ft_push(stk_a, stk_b, 'a');
	}
}
