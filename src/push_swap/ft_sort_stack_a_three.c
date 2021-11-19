/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:47:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 09:51:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_a_top_equal_pivot(t_stack *stk_a, int pivot);
static void	ft_a_top_minus1_equal_pivot(t_stack *stk_a, int pivot);
static void	ft_a_top_minus2_equal_pivot(t_stack *stk_a, int pivot);

void	ft_sort_three_stack_a(t_stack *stk_a, int len)
{
	int	pivot;

	pivot = ft_quick_pivot(stk_a, len, 1);
	if (stk_a->values[stk_a->top] == pivot)
		ft_a_top_equal_pivot(stk_a, pivot);
	else if (stk_a->values[stk_a->top - 1] == pivot)
		ft_a_top_minus1_equal_pivot(stk_a, pivot);
	else
		ft_a_top_minus2_equal_pivot(stk_a, pivot);
}

static void	ft_a_top_equal_pivot(t_stack *stk_a, int pivot)
{
	if (stk_a->values[stk_a->top - 1] < pivot)
		ft_swap_one(stk_a, 'a');
	else
	{
		ft_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
		ft_reverse_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
	}
}

static void	ft_a_top_minus1_equal_pivot(t_stack *stk_a, int pivot)
{
	if (stk_a->values[stk_a->top] > pivot)
	{
		ft_swap_one(stk_a, 'a');
		ft_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
		ft_reverse_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
	}
}
static void	ft_a_top_minus2_equal_pivot(t_stack *stk_a, int pivot)
{
	if (stk_a->values[stk_a->top] < pivot)
	{
		ft_rotate(stk_a, 'a');
		ft_sort_two_stack_a(stk_a);
		ft_reverse_rotate(stk_a, 'a');
	}
	else
	{
		ft_swap_one(stk_a, 'a');
		ft_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
		ft_reverse_rotate(stk_a, 'a');
	}
}
