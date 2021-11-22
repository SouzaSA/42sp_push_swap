/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:30:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/21 21:50:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_partition(t_vars *vars, int push_to_b, int pivot, int flag);
static int	ft_more_three(t_vars *vars, int *cnt, int pivot);

void	ft_separate_stk_a(t_vars *vars, int blk, int flag)
{
	int	pivot;
	int	flag_b;
	int	blk_b;

	if (blk < 4)
	{
		if (blk == 2)
			ft_sort_two_stack_a(&vars->stk_a, &vars->cmds);
		else if (blk == 3)
			ft_sort_three_stack_a(&vars->stk_a, blk, &vars->cmds);
		return ;
	}
	blk_b = blk / 2;
	if (blk % 2)
		blk_b = blk / 2 + 1;
	pivot = ft_quick_pivot(&vars->stk_a, blk, blk_b);
	flag_b = ft_partition(vars, blk_b, pivot, flag);
	ft_separate_stk_a(vars, blk - blk_b - flag_b, flag);
	if (flag_b && vars->stk_b.values[0] == pivot)
	{
		ft_rev_rotate(&vars->stk_b, 'b', &vars->cmds);
		ft_push(vars, 'a');
	}
	if (blk_b != vars->stk_b.top + 1)
		ft_separate_stk_b(vars, blk_b, 1);
	else
		ft_separate_stk_b(vars, blk_b, 0);
}

static int	ft_partition(t_vars *vars, int push_to_b, int pivot, int flag)
{
	int	cnt_rotate_a;
	int	is_gt_three;
	int	less_three;

	cnt_rotate_a = 0;
	is_gt_three = 0;
	less_three = 0;
	if (push_to_b <= 3)
		less_three = 1;
	while (push_to_b)
	{
		if (vars->stk_a.values[vars->stk_a.top] < pivot)
		{
			ft_push(vars, 'b');
			push_to_b--;
		}
		else if (!less_three && vars->stk_a.values[vars->stk_a.top] == pivot)
			is_gt_three = ft_more_three(vars, &cnt_rotate_a, pivot);
		else
		{
			ft_rotate(&vars->stk_a, 'a', &vars->cmds);
			cnt_rotate_a++;
		}
	}
	while (flag && cnt_rotate_a--)
		ft_rev_rotate(&vars->stk_a, 'a', &vars->cmds);
	return (is_gt_three);
}

static int	ft_more_three(t_vars *vars, int *cnt, int pivot)
{
	ft_push(vars, 'b');
	if (vars->stk_a.values[vars->stk_a.top] > pivot)
	{
		ft_rotate_both(vars);
		(*cnt)++;
	}
	else
		ft_rotate(&vars->stk_b, 'b', &vars->cmds);
	return (1);
}
