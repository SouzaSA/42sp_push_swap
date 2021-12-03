/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:21 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/03 19:54:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_manage_three_or_less(t_vars *vars, int blk);
static int	ft_partition(t_vars *vars, int pivot, int cnt_b, int *pushed);
static void	ft_push_pivot(t_vars *vars, int *cnt_rotate, int *cnt, int pivot);

void	ft_separate_stk_b(t_vars *vars, int blk, int flag)
{
	int	pivot;
	int	cnt;
	int	cnt_push_to_a;
	int	cnt_rotate_b;
	int	pushed;

	if (blk < 4)
	{
		ft_manage_three_or_less(vars, blk);
		return ;
	}
	cnt_push_to_a = (blk) / 2 - 1;
	if (blk % 2)
		cnt_push_to_a = (blk) / 2;
	pivot = ft_quick_pivot(&vars->stk_b, blk, cnt_push_to_a);
	cnt_rotate_b = ft_partition(vars, pivot, blk, &pushed);
	ft_separate_stk_a(vars, pushed, 1);
	ft_rev_rotate_both(vars);
	cnt = 1;
	while (flag && cnt++ < cnt_rotate_b)
		ft_rev_rotate(&vars->stk_b, 'b', &vars->cmds);
	blk = cnt_rotate_b;
	ft_separate_stk_b(vars, blk, flag);
}

static void	ft_manage_three_or_less(t_vars *vars, int blk)
{
	if (blk == 1)
		ft_push(vars, 'a');
	else if (blk == 2)
		ft_sort_two_stack_b(vars);
	else if (blk == 3)
		ft_sort_three_stack_b(vars, blk);
}

static int	ft_partition(t_vars *vars, int pivot, int cnt_b, int *pushed)
{
	int	cnt_rotate_b;

	cnt_rotate_b = 0;
	*pushed = 0;
	while (cnt_b--)
	{
		if (vars->stk_b.values[vars->stk_b.top] > pivot)
		{
			ft_push(vars, 'a');
			*pushed += 1;
		}
		else if (vars->stk_b.values[vars->stk_b.top] == pivot)
			ft_push_pivot(vars, &cnt_rotate_b, &cnt_b, pivot);
		else
		{
			ft_rotate(&vars->stk_b, 'b', &vars->cmds);
			cnt_rotate_b++;
		}
	}
	return (cnt_rotate_b);
}

static void	ft_push_pivot(t_vars *vars, int *cnt_rotate, int *cnt, int pivot)
{
	ft_push(vars, 'a');
	if (vars->stk_b.values[vars->stk_b.top] < pivot && *cnt)
	{
		ft_rotate_both(vars);
		*cnt_rotate += 1;
		*cnt -= 1;
	}
	else
		ft_rotate(&vars->stk_a, 'a', &vars->cmds);
}
