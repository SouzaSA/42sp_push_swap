/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/24 18:26:22 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int	num_in_wrong_pos;

	i = 0;
	num_in_wrong_pos = 0;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] != i)
			num_in_wrong_pos++;
		i++;
	}
	if (num_in_wrong_pos >= stack_a->size / 2)
		ft_order_big_mess(stack_a, stack_b);
	else
		ft_order_small_mess(stack_a, stack_b);
	return (0);
}
