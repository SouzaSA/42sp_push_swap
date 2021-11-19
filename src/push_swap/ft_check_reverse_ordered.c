/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_reverse_ordered.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:44:49 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 11:00:49 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_sort_rev(t_stack *stk_a, t_stack *stk_b, int i);

int	ft_check_reverse_ordered(t_stack *stk_a, t_stack *stk_b)
{
	int i;

	i = 0;
	if (stk_b->top >= 0)
		return (0);
	while (i++ <= stk_a->top)
	{
		if (stk_a->values[i] < stk_a->values[i - 1] && i <= stk_a->top)
			return (0);
	}
	if (stk_a->top == 1)
		ft_sort_two_stack_a(stk_a);
	else if (stk_a->top == 2 || stk_a->top == 3)
		return (0);
	else if (stk_a->top > 1)
		ft_sort_rev(stk_a, stk_b, stk_a->top);
	return (1);
}

static void	ft_sort_rev(t_stack *stk_a, t_stack *stk_b, int i)
{
	ft_rotate(stk_a, 'a');
	ft_rotate(stk_a, 'a');
	ft_rotate(stk_a, 'a');
	i -= 2;
	while (i--)
		ft_push(stk_a, stk_b, 'b');
	if (stk_a->top > 0 && stk_b->top > 0)
		ft_swap_both(stk_a, stk_b);
	else
		ft_swap_one(stk_a, 'a');
	if (stk_b->top > 1)
	{
		ft_reverse_rotate_both(stk_a, stk_b);
		ft_push(stk_a, stk_b, 'a');
	}
	else
		ft_reverse_rotate(stk_a, 'a');
	while (stk_b->top > 1)
	{
		ft_reverse_rotate(stk_b, 'b');
		ft_push(stk_a, stk_b, 'a');
	}
	ft_push(stk_a, stk_b, 'a');
	ft_push(stk_a, stk_b, 'a');
}
