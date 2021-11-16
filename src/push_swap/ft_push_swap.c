/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/16 16:35:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_swap(t_stack *stk_a, t_stack *stk_b)
{
	if (!ft_is_ordered_stk_a(stk_a))
	{
		if (!check_rev(stk_a, stk_b))
		{
			if (stk_a->top == 2)
				sort_three(stk_a);
			else if (stk_a->top != 4 && stk_a->top != 5)
				ft_separation_steck_a(stk_a, stk_b, 0);
			else
				sort_stack_a(stk_a, stk_b, stk_a->top + 1);
		}
	}
	return (0);
}
