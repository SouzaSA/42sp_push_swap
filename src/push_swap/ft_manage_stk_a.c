/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:30:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:17:52 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_partition(t_vars *vars, int push_to_b, int *i);
static void	ft_push_to_stack_a(t_vars *vars, int pivot_a);
static int	ft_more_three(t_vars *vars, int *cnt, int pivot);

void	ft_separate_stk_a(t_vars *vars, int blk, int flag)
{
	int	flag_b;
	int	len_blk_a;
	int	i[2];
	int	push_to_b[2];

	len_blk_a = blk;
	if (len_blk_a < 4)
	{
		if (len_blk_a == 2)
			ft_sort_two_stack_a(&vars->stk_a, &vars->cmds);
		else if (len_blk_a == 3)
			ft_sort_three_stack_a(&vars->stk_a, len_blk_a, &vars->cmds);
		return ;
	}
	push_to_b[0] = len_blk_a / 2;
	if (len_blk_a % 2)
		push_to_b[0] = len_blk_a / 2 + 1;
	i[0] = ft_quick_pivot(&vars->stk_a, len_blk_a, push_to_b[0]);
	i[1] = flag;
	flag_b = ft_partition(vars, push_to_b[0], i);
	ft_separate_stk_a(vars, vars->stk_a.top + 1, flag);
	if (flag_b)
		ft_push_to_stack_a(vars, i[0]);
	if (push_to_b[0] != vars->stk_b.top + 1)
	{
		push_to_b[1] = 1;
		ft_separate_stk_b(vars, push_to_b);
	}
	else
	{
		push_to_b[1] = 0;
		ft_separate_stk_b(vars, push_to_b);
	}
}

static int	ft_partition(t_vars *vars, int push_to_b, int *i)
{
	int	flag;
	int	less_three;
	int	cnt_rotate_a;

	cnt_rotate_a = 0;
	flag = 0;
	less_three = 1;
	if (push_to_b > 3)
		less_three = 0;
	while (push_to_b)
		if (vars->stk_a.values[vars->stk_a.top] < i[0])
		{
			ft_push(vars, 'b');
			push_to_b--;
		}
		else if (!less_three && vars->stk_a.values[vars->stk_a.top] == i[0])
			flag = ft_more_three(vars, &cnt_rotate_a, i[0]);
		else
		{
			ft_rotate(&vars->stk_a, 'a', &vars->cmds);
			cnt_rotate_a++;
		}
	while (i[1] && cnt_rotate_a--)
		ft_rev_rotate(&vars->stk_a, 'a', &vars->cmds);
	return (flag);
}

static void	ft_push_to_stack_a(t_vars *vars, int pivot_a)
{
	if (pivot_a == vars->stk_b.values[vars->stk_b.top])
	{
		ft_rev_rotate(&vars->stk_b, 'b', &vars->cmds);
		ft_push(vars, 'a');
	}
}

static int	ft_more_three(t_vars *vars, int *cnt, int pivot)
{
	ft_push(vars, 'b');
	if (vars->stk_a.values[vars->stk_b.top] > pivot)
	{
		ft_rotate_both(vars);
		(*cnt)++;
	}
	else
		ft_rotate(&vars->stk_b, 'b', &vars->cmds);
	return (1);
}
