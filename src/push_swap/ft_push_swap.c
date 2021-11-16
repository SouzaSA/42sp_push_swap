/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/15 21:00:13 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_swap(t_stack *stk_a, t_stack *stk_b)
{
	if (!ft_is_ordered_stk_a(stk_a))
	{
		if (!check_rev(a, b))
		{
			if (i == 2)
				sort_two_steck_a(a);
			else if (i == 3)
				return (FALSE);
			else if (i > 1)
				sort_rev(a, b, i);
			if (i == 3)
				sort_three(a, i);
			else if (i != 5 && i != 6)
				separation_steck_a(a, b, END, FALSE);
			else
				sort_steck_a(a, b, i);
		}
	}
	return (0);
}
