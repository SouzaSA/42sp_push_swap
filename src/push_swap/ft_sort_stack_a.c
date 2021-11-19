/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:07:40 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 09:49:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_sort_a(t_stack *stk_a, int pivot_a);

void	ft_sort_stack_a(t_stack *stk_a, t_stack *stk_b, int len)
{
	int	pivot_a;
	int	pivot_b;
	int	cnt;

	cnt = len / 2;
	pivot_a = ft_quick_pivot(stk_a, len, cnt);
	pivot_b = ft_quick_pivot(stk_a, len, 1);
	while (cnt)
	{
		if (stk_a->values[stk_a->top] < pivot_a)
		{
			ft_push(stk_a, stk_b, 'b');
			if (stk_b->top > 0 && stk_b->values[stk_b->top] < pivot_b)
				ft_rotate(stk_b, 'b');
			cnt--;
		}
		else
			ft_rotate(stk_a, 'a');
	}
	pivot_a = ft_quick_pivot(stk_a, stk_a->top + 1, 1);
	ft_sort_a(stk_a, pivot_a);
	cnt = stk_b->top + 1;
	if (cnt == 2)
		ft_sort_two_stack_b(stk_a, stk_b);
	else
		ft_sort_three_stack_b(stk_a, stk_b, cnt);
}

static void	ft_sort_a(t_stack *stk_a, int pivot_a)
{
	if (stk_a->values[stk_a->top] == pivot_a)
	{
		if (stk_a->values[stk_a->top - 1] > pivot_a)
			ft_reverse_rotate(stk_a, 'a');
		else
			ft_swap_one(stk_a, 'a');
	}
	else if (stk_a->values[stk_a->top - 1] == pivot_a)
	{
		if (stk_a->values[stk_a->top] > pivot_a)
		{
			ft_rotate(stk_a, 'a');
			ft_swap_one(stk_a, 'a');
		}
	}
	else
	{
		if (stk_a->values[stk_a->top] > pivot_a)
			ft_rotate(stk_a, 'a');
		else
		{
			ft_swap_one(stk_a, 'a');
			ft_rotate(stk_a, 'a');
		}
	}
}
