/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:07:40 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/17 10:56:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_a0_equal_pivot(t_stack *stk_a, int pivot);
static void	ft_a1_equal_pivot(t_stack *stk_a, int pivot);
static void	ft_a2_equal_pivot(t_stack *stk_a, int pivot);

void	ft_sort_two_stack_a(t_stack *stk_a)
{
	if (stk_a->values[0] > stk_a->values[1])
		ft_swap_one(stk_a, 'a');
}

void	ft_sort_three_stack_a(t_stack *stk_a, int len)
{
	int	pivot;

	pivot = ft_quick_pivot(stk_a->values, len, 1);
	if (stk_a->values[0] == pivot)
		ft_a0_equal_pivot(stk_a, pivot);
	else if (stk_a->values[1] == pivot)
		ft_a1_equal_pivot(stk_a, pivot);
	else
		ft_a2_equal_pivot(stk_a, pivot);
}

static void	ft_a0_equal_pivot(t_stack *stk_a, int pivot)
{
	if (stk_a->values[1] < pivot)
		ft_swap_one(stk_a, 'a');
	else
	{
		ft_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
		ft_reverse_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
	}
}

static void	ft_a1_equal_pivot(t_stack *stk_a, int pivot)
{
	if (stk_a->values[0] > pivot)
	{
		ft_swap_one(stk_a, 'a');
		ft_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
		ft_reverse_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
	}
}

static void	ft_a2_equal_pivot(t_stack *stk_a, int pivot)
{
	if (stk_a->values[0] < pivot)
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
