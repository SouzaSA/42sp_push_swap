/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:42:21 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:21:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_three(t_stack *stk_a, int len, t_list **cmds)
{
	int	pivot;

	pivot = ft_quick_pivot(stk_a, len, 1);
	if (stk_a->values[2] == pivot)
	{
		if (stk_a->values[0] > stk_a->values[1])
			ft_swap_one(stk_a, 'a', cmds);
		else
			ft_rev_rotate(stk_a, 'a', cmds);
	}
	else if (stk_a->values[1] == pivot && stk_a->values[0] < stk_a->values[2])
	{
		ft_rotate(stk_a, 'a', cmds);
		ft_swap_one(stk_a, 'a', cmds);
	}
	else
	{
		if (stk_a->values[0] < stk_a->values[1])
			ft_swap_one(stk_a, 'a', cmds);
		ft_rotate(stk_a, 'a', cmds);
	}
}
