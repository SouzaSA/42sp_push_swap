/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_b_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:50:38 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/21 17:48:44 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_two_stack_b(t_vars *vars)
{
	t_stack	*stk_b;

	stk_b = &vars->stk_b;
	if (stk_b->values[stk_b->top] < stk_b->values[stk_b->top - 1])
		ft_swap_one(stk_b, 'b', &vars->cmds);
	ft_push(vars, 'a');
	ft_push(vars, 'a');
}
