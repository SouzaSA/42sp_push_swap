/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:07:40 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/21 22:11:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_send_b(t_vars *vars, int cnt, int pivot_a, int pivot_b);
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
		cnt = ft_send_b(vars, cnt, pivot_a, pivot_b);
	}
	pivot_a = ft_quick_pivot(&vars->stk_a, vars->stk_a.top + 1, 1);
	ft_sort_a(&vars->stk_a, pivot_a, &vars->cmds);
	cnt = vars->stk_b.top + 1;
	if (cnt == 2)
		ft_sort_two_stack_b(vars);
	else
		ft_sort_three_stack_b(vars, cnt);
}

static int	ft_send_b(t_vars *vars, int cnt, int pivot_a, int pivot_b)
{
	t_stack	*stk_b;

	stk_b = &vars->stk_b;
	if (vars->stk_a.values[vars->stk_a.top] < pivot_a)
	{
		ft_push(vars, 'b');
		if (stk_b->top > 0 && stk_b->values[stk_b->top] < pivot_b)
			ft_rotate(stk_b, 'b', &vars->cmds);
		cnt--;
	}
	else
		ft_rotate(&vars->stk_a, 'a', &vars->cmds);
	return (cnt);
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
