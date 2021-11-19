/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_b_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:51:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 09:51:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_b0_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot);
static void	ft_b1_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot);
static void	ft_b2_equal_pivot(t_stack *stk_a, t_stack *stk_b, int pivot);

void	ft_sort_three_stack_b(t_stack *stk_a, t_stack *stk_b, int len)
{
	int	pivot;

	pivot = ft_quick_pivot(stk_b, len, 1);
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
		ft_sort_two_stack_b(stk_a, stk_b);
	}
	else
	{
		ft_swap_one(stk_b, 'b');
		ft_push(stk_a, stk_b, 'a');
		ft_sort_two_stack_b(stk_a, stk_b);
	}
}
