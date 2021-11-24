/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 16:09:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_swap(t_vars *vars)
{
	if (!ft_is_sorted_stk_a(&vars->stk_a))
	{
		if (!ft_check_reverse_sorted(vars))
		{
			if (vars->stk_a.size == 3)
				ft_sort_three(&vars->stk_a, 3, &vars->cmds);
			else if (vars->stk_a.size == 4)
				ft_sort_four(vars, 4);
			else if (vars->stk_a.size == 5 || vars->stk_a.size == 6)
				ft_sort_stack_a(vars, vars->stk_a.size);
			else
				ft_separate_stk_a(vars, vars->stk_a.size, 0);
		}
	}
	return (0);
}
