/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:47:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:19:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_a_top_eq_pivot(t_stack *stk_a, int pivot, t_list **cmds);
static void	ft_a_top_minus1_eq_pivot(t_stack *stk_a, int pivot, t_list **cmds);
static void	ft_a_top_minus2_eq_pivot(t_stack *stk_a, int pivot, t_list **cmds);

void	ft_sort_three_stack_a(t_stack *stk_a, int len, t_list **cmds)
{
	int	pivot;

	pivot = ft_quick_pivot(stk_a, len, 1);
	if (stk_a->values[stk_a->top] == pivot)
		ft_a_top_eq_pivot(stk_a, pivot, cmds);
	else if (stk_a->values[stk_a->top - 1] == pivot)
		ft_a_top_minus1_eq_pivot(stk_a, pivot, cmds);
	else
		ft_a_top_minus2_eq_pivot(stk_a, pivot, cmds);
}

static void	ft_a_top_eq_pivot(t_stack *stk_a, int pivot, t_list **cmds)
{
	if (stk_a->values[stk_a->top - 1] < pivot)
		ft_swap_one(stk_a, 'a', cmds);
	else
	{
		ft_rotate(stk_a, 'a', cmds);
		ft_swap_one(stk_a, 'a', cmds);
		ft_rev_rotate(stk_a, 'a', cmds);
		ft_swap_one(stk_a, 'a', cmds);
	}
}

static void	ft_a_top_minus1_eq_pivot(t_stack *stk_a, int pivot, t_list **cmds)
{
	if (stk_a->values[stk_a->top] > pivot)
	{
		ft_swap_one(stk_a, 'a', cmds);
		ft_rotate(stk_a, 'a', cmds);
		ft_swap_one(stk_a, 'a', cmds);
		ft_rev_rotate(stk_a, 'a', cmds);
		ft_swap_one(stk_a, 'a', cmds);
	}
}
static void	ft_a_top_minus2_eq_pivot(t_stack *stk_a, int pivot, t_list **cmds)
{
	if (stk_a->values[stk_a->top] < pivot)
	{
		ft_rotate(stk_a, 'a', cmds);
		ft_sort_two_stack_a(stk_a, cmds);
		ft_rev_rotate(stk_a, 'a', cmds);
	}
	else
	{
		ft_swap_one(stk_a, 'a', cmds);
		ft_rotate(stk_a, 'a', cmds);
		ft_swap_one(stk_a, 'a', cmds);
		ft_rev_rotate(stk_a, 'a', cmds);
	}
}
