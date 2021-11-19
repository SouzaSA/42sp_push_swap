/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:21 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:18:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_partition(t_vars *vars, int pivot, int cnt_b);

void	ft_separate_stk_b(t_vars *vars, int *cnt_b)
{
	int	pivot;
	int	cnt;
	int	cnt_push_to_a;
	int	cnt_rotate_b;

	if (cnt_b[0] < 4)
	{
		if (cnt_b[0] == 1)
			ft_push(vars, 'a');
		else if (cnt_b[0] == 2)
			ft_sort_two_stack_b(vars);
		else if (cnt_b[0] == 3)
			ft_sort_three_stack_b(vars, cnt_b[0]);
		return ;
	}
	cnt_push_to_a = cnt_b[0] / 2 - 1;
	if (cnt_b[0] % 2)
		cnt_push_to_a = cnt_b[0] / 2;
	pivot = ft_quick_pivot(&vars->stk_b, cnt_b[0], cnt_push_to_a);
	cnt_rotate_b = ft_partition(vars, pivot, cnt_b[0]);
	ft_separate_stk_a(vars, cnt_push_to_a, 1);
	ft_rev_rotate_both(vars);
	cnt = 1;
	while (cnt_b[1] && cnt++ < cnt_rotate_b)
		ft_rev_rotate(&vars->stk_b, 'b', &vars->cmds);
	cnt_b[0] = cnt_rotate_b;
	ft_separate_stk_b(vars, cnt_b);
}

static int	ft_partition(t_vars *vars, int pivot, int cnt_b)
{
	int	cnt_rotate_b;

	cnt_rotate_b = 0;
	while (cnt_b--)
		if (vars->stk_b.values[vars->stk_b.top] > pivot)
			ft_push(vars, 'a');
		else if (vars->stk_b.values[vars->stk_b.top] == pivot)
		{
			ft_push(vars, 'a');
			if (vars->stk_b.values[vars->stk_b.top] < pivot && cnt_b)
			{
				ft_rotate_both(vars);
				cnt_rotate_b++;
				cnt_b--;
			}
			else
				ft_rotate(&vars->stk_a, 'a', &vars->cmds);
		}
		else
		{
			ft_rotate(&vars->stk_b, 'b', &vars->cmds);
			cnt_rotate_b++;
		}
	return (cnt_rotate_b);
}
