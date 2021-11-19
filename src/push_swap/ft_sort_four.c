/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:54 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:18:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_four(t_vars *vars, int len)
{
	int	min_idx;
	int	min_val;

	min_idx = ft_smallest_int_idx(vars->stk_a.values, len);
	min_val = vars->stk_a.values[min_idx];
	if (min_idx >= len / 2)
	{
		while (min_val != vars->stk_a.values[vars->stk_a.top])
			ft_rotate(&vars->stk_a, 'a', &vars->cmds);
	}
	else
	{
		while (min_val != vars->stk_a.values[vars->stk_a.top])
			ft_rev_rotate(&vars->stk_a, 'a', &vars->cmds);
	}
	if(!ft_is_ordered_stk_a(&vars->stk_a))
	{
		ft_push(vars, 'b');
		ft_sort_three(&vars->stk_a, 3, &vars->cmds);
		ft_push(vars, 'a');
	}
}
