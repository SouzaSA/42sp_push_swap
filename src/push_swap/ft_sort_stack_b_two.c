/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_b_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:50:38 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 09:50:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_two_stack_b(t_stack *stk_a, t_stack *stk_b)
{
	if (stk_b->values[0] > stk_b->values[1])
		ft_swap_one(stk_b, 'b');
	ft_push(stk_a, stk_b, 'a');
	ft_push(stk_a, stk_b, 'a');
}
