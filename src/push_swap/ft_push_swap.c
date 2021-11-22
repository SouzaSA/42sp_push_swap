/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 20:13:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_swap(t_vars *vars)
{
	if (!ft_is_ordered_stk_a(&vars->stk_a))
	{
		if (!ft_check_reverse_ordered(vars))
		{
			if (vars->stk_a.top == 2)
				ft_sort_three(&vars->stk_a, 3, &vars->cmds);
			else if (vars->stk_a.top == 3)
				ft_sort_four(vars, 4);
			else if (vars->stk_a.top == 4 || vars->stk_a.top == 5)
				ft_sort_stack_a(vars, vars->stk_a.top + 1);
			else
				ft_separate_stk_a(vars, vars->stk_a.top + 1, 0);
		}
	}
	return (0);
}
