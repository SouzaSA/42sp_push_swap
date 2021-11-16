/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:08:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/16 09:30:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_b0_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot);
static void	ft_b1_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot);
static void	ft_b2_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot);

void	ft_sort_two_steck_b(t_stack *stk_a, t_stack *stk_b)
{
	if (stk_b->values[0] < stk_b->values[1])
		ft_swap_one(stk_b, 'a');
	ft_push(stk_a, stk_b, 'a');
	ft_push(stk_a, stk_b, 'a');
}

void	ft_sort_three_steck_b(t_stack *stk_a, t_stack *stk_b, int len)
{
	int	pivot;

	pivot = ft_quick_pivot(stk_b->values, len, 1);
	if (stk_b->values[0] == pivot)
		ft_b0_equal_pivot(stk_a, stk_b, pivot);
	else if (stk_b->values[1] == pivot)
		ft_b1_equal_pivot(stk_a, stk_b, pivot);
	else
		ft_b2_equal_pivot(stk_a, stk_b, pivot);
}

static void	ft_b0_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot)
{
	if (stk_b->values[1] > pivot)
	{
		ft_swap_one(stk_b, 'b');
		ft_push(stk_a, stk_b, 'a');
		ft_push(stk_a, stk_b, 'a');
		ft_push(stk_a, stk_b, 'a');
	}
	else
	{
		ft_push(stk_a, stk_b, 'a');
		ft_swap_one(stk_b, 'b');
		ft_push(stk_a, stk_b, 'a');
		ft_swap_one(stk_a, 'a');
		ft_push(stk_a, stk_b, 'a');
	}
}

static void	ft_b1_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot)
{
	if (stk_b->values[0] > pivot)
	{
		ft_push(stk_a, stk_b, 'a');
		ft_push(stk_a, stk_b, 'a');
		ft_push(stk_a, stk_b, 'a');
	}
	else
	{
		ft_swap_one(stk_b, 'b');
		ft_push(stk_a, stk_b, 'a');
		ft_swap_one(stk_b, 'b');
		ft_push(stk_a, stk_b, 'a');
		ft_swap_one(stk_a, 'a');
		ft_push(stk_a, stk_b, 'a');
	}
}

static void	ft_b2_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot)
{
	if (stk_b->values[0] > pivot)
	{
		ft_push(stk_a, stk_b, 'a');
		ft_sort_two_steck_b(stk_a, stk_b);
	}
	else
	{
		ft_swap_one(stk_b, 'b');
		ft_push_a(stk_a, stk_b, 'a');
		ft_sort_two_steck_b(stk_a, stk_b);
	}
}
