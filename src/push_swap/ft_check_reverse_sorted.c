/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_reverse_sorted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:44:49 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/23 11:10:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_sort_rev(t_vars *vars, int i);

int	ft_check_reverse_sorted(t_vars *vars)
{
	int	i;

	i = 1;
	if (vars->stk_b.top >= 0)
		return (0);
	while (i <= vars->stk_a.top)
	{
		if (vars->stk_a.values[i] < vars->stk_a.values[i - 1]
			&& i <= vars->stk_a.top)
			return (0);
		i++;
	}
	if (vars->stk_a.top == 1)
		ft_sort_two_stack_a(&vars->stk_a, &vars->cmds);
	else if (vars->stk_a.top == 2 || vars->stk_a.top == 3)
		return (0);
	else if (vars->stk_a.top > 1)
		ft_sort_rev(vars, vars->stk_a.top);
	return (1);
}

static void	ft_sort_rev(t_vars *vars, int i)
{
	ft_rotate(&vars->stk_a, 'a', &vars->cmds);
	ft_rotate(&vars->stk_a, 'a', &vars->cmds);
	ft_rotate(&vars->stk_a, 'a', &vars->cmds);
	i -= 2;
	while (i--)
		ft_push(vars, 'b');
	if (vars->stk_a.top > 0 && vars->stk_b.top > 0)
		ft_swap_both(vars);
	else
		ft_swap_one(&vars->stk_a, 'a', &vars->cmds);
	if (vars->stk_b.top > 1)
	{
		ft_rev_rotate_both(vars);
		ft_push(vars, 'a');
	}
	else
		ft_rev_rotate(&vars->stk_a, 'a', &vars->cmds);
	while (vars->stk_b.top > 1)
	{
		ft_rev_rotate(&vars->stk_b, 'b', &vars->cmds);
		ft_push(vars, 'a');
	}
	ft_push(vars, 'a');
	ft_push(vars, 'a');
}
