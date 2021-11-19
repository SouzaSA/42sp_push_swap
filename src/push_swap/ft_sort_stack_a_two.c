/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:47:53 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 09:48:17 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_two_stack_a(t_stack *stk_a)
{
	if (stk_a->values[0] < stk_a->values[1])
		ft_swap_one(stk_a, 'a');
}
