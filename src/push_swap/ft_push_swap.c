/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/09 16:37:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_swap(t_stack *stk_a, t_stack *stk_b)
{
	int	i;
	int	num_wrong_pos;

	i = stk_a->top;
	num_wrong_pos = 0;
	while (i > 0)
	{
		if (stk_a->values[i] > stk_b->values[i - 1])
			num_wrong_pos++;
		i--;
	}
	if (num_wrong_pos < stk_a->size / 10 || stk_a->top < 6)
		ft_order_small_mess(stk_a, stk_b);
	else
		ft_order_big_mess(stk_a, stk_b);
	return (0);
}
