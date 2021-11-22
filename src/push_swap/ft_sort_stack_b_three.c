/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_b_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:51:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/21 11:42:24 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_b_top_eq_pivot(t_vars *vars, int pivot);
static void	ft_b_top_minus1_eq_pivot(t_vars *vars, int pivot);
static void	ft_b_top_minus2_eq_pivot(t_vars *vars, int pivot);

void	ft_sort_three_stack_b(t_vars *vars, int len)
{
	int	pivot;

	pivot = ft_quick_pivot(&vars->stk_b, len, 1);
	if (vars->stk_b.values[vars->stk_b.top] == pivot)
		ft_b_top_eq_pivot(vars, pivot);
	else if (vars->stk_b.values[vars->stk_b.top - 1] == pivot)
		ft_b_top_minus1_eq_pivot(vars, pivot);
	else
		ft_b_top_minus2_eq_pivot(vars, pivot);
}

static void	ft_b_top_eq_pivot(t_vars *vars, int pivot)
{
	if (vars->stk_b.values[vars->stk_b.top - 1] > pivot)
	{
		ft_swap_one(&vars->stk_b, 'b', &vars->cmds);
		ft_push(vars, 'a');
		ft_push(vars, 'a');
		ft_push(vars, 'a');
	}
	else
	{
		ft_push(vars, 'a');
		ft_swap_one(&vars->stk_b, 'b', &vars->cmds);
		ft_push(vars, 'a');
		ft_swap_one(&vars->stk_a, 'a', &vars->cmds);
		ft_push(vars, 'a');
	}
}

static void	ft_b_top_minus1_eq_pivot(t_vars *vars, int pivot)
{
	if (vars->stk_b.values[vars->stk_b.top] > pivot)
	{
		ft_push(vars, 'a');
		ft_push(vars, 'a');
		ft_push(vars, 'a');
	}
	else
	{
		ft_swap_one(&vars->stk_b, 'b', &vars->cmds);
		ft_push(vars, 'a');
		ft_swap_one(&vars->stk_b, 'b', &vars->cmds);
		ft_push(vars, 'a');
		ft_swap_one(&vars->stk_a, 'a', &vars->cmds);
		ft_push(vars, 'a');
	}
}

static void	ft_b_top_minus2_eq_pivot(t_vars *vars, int pivot)
{
	if (vars->stk_b.values[vars->stk_b.top] > pivot)
	{
		ft_push(vars, 'a');
		ft_sort_two_stack_b(vars);
	}
	else
	{
		ft_swap_one(&vars->stk_b, 'b', &vars->cmds);
		ft_push(vars, 'a');
		ft_sort_two_stack_b(vars);
	}
}
