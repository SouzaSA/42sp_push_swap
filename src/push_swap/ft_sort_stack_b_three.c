/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_b_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:51:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:20:49 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_b0_equal_pivot(t_vars *vars, int pivot);
static void	ft_b1_equal_pivot(t_vars *vars, int pivot);
static void	ft_b2_equal_pivot(t_vars *vars, int pivot);

void	ft_sort_three_stack_b(t_vars *vars, int len)
{
	int	pivot;

	pivot = ft_quick_pivot(&vars->stk_b, len, 1);
	if (vars->stk_b.values[0] == pivot)
		ft_b0_equal_pivot(vars, pivot);
	else if (vars->stk_b.values[1] == pivot)
		ft_b1_equal_pivot(vars, pivot);
	else
		ft_b2_equal_pivot(vars, pivot);
}

static void	ft_b0_equal_pivot(t_vars *vars, int pivot)
{
	if (vars->stk_b.values[1] > pivot)
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

static void	ft_b1_equal_pivot(t_vars *vars, int pivot)
{
	if (vars->stk_b.values[0] > pivot)
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

static void	ft_b2_equal_pivot(t_vars *vars, int pivot)
{
	if (vars->stk_b.values[0] > pivot)
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
