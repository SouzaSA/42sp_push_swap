/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:07:40 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:20:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_sort_a(t_stack *stk_a, int pivot_a, t_list **cmds);

void	ft_sort_stack_a(t_vars *vars, int len)
{
	int	pivot_a;
	int	pivot_b;
	int	cnt;

	cnt = len / 2;
	pivot_a = ft_quick_pivot(&vars->stk_a, len, cnt);
	pivot_b = ft_quick_pivot(&vars->stk_a, len, 1);
	while (cnt)
	{
		if (vars->stk_a.values[vars->stk_a.top] < pivot_a)
		{
			ft_push(vars, 'b');
			if (vars->stk_b.top > 0 && vars->stk_b.values[vars->stk_b.top] < pivot_b)
				ft_rotate(&vars->stk_b, 'b', &vars->cmds);
			cnt--;
		}
		else
			ft_rotate(&vars->stk_a, 'a', &vars->cmds);
	}
	pivot_a = ft_quick_pivot(&vars->stk_a, vars->stk_a.top + 1, 1);
	ft_sort_a(&vars->stk_a, pivot_a, &vars->cmds);
	cnt = vars->stk_b.top + 1;
	if (cnt == 2)
		ft_sort_two_stack_b(vars);
	else
		ft_sort_three_stack_b(vars, cnt);
}

static void	ft_sort_a(t_stack *stk_a, int pivot_a, t_list **cmds)
{
	if (stk_a->values[stk_a->top] == pivot_a)
	{
		if (stk_a->values[stk_a->top - 1] > pivot_a)
			ft_rev_rotate(stk_a, 'a', cmds);
		else
			ft_swap_one(stk_a, 'a', cmds);
	}
	else if (stk_a->values[stk_a->top - 1] == pivot_a)
	{
		if (stk_a->values[stk_a->top] > pivot_a)
		{
			ft_rotate(stk_a, 'a', cmds);
			ft_swap_one(stk_a, 'a', cmds);
		}
	}
	else
	{
		if (stk_a->values[stk_a->top] > pivot_a)
			ft_rotate(stk_a, 'a', cmds);
		else
		{
			ft_swap_one(stk_a, 'a', cmds);
			ft_rotate(stk_a, 'a', cmds);
		}
	}
}
