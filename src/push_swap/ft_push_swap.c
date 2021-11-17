/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/17 20:43:35 by sde-alva         ###   ########.fr       */
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
				ft_sort_three(stk_a, 3);
			else if (stk_a->top != 4 && stk_a->top != 5)
				ft_separate_stk_a(stk_a, stk_b, stk_a->top + 1, 0);
			else
				ft_sort_stack_a(stk_a, stk_b, stk_a->top + 1);
		}
	}
	return (0);
}
