/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:38:24 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/17 12:45:42 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int	check_rev(t_stack *stk_a, t_stack *stk_b)
{
	int i;

	i = 0;
	if (stk_b->top < 0)
		return (0);
	while (i++ <= stk_a->top)
	{
		if (stk_a->values[i] > stk_a->values[i - 1] && i <= stk_a->top)
			return (0);
	}
	if (stk_a->top == 1)
		ft_sort_two_stack_a(stk_a);
	else if (stk_a->top == 2)
		return (0);
	else if (stk_a->top > 1)
		ft_sort_rev(stk_a, stk_b, stk_a->top);
	return (1);
}

static void	ft_sort_a(t_stack *stk_a, int midl_a)
{
	if (stk_a->values[0] == midl_a)
	{
		if (stk_a->values[1] > midl_a)
			ft_reverse_rotate(stk_a, 'a');
		else
			ft_swap_one(stk_a, 'a');
	}
	else if (stk_a->values[1] == midl_a)
	{
		if (stk_a->values[0] > midl_a)
		{
			ft_rotate(stk_a, 'a');
			ft_swap_one(stk_a, 'a');
		}
	}
	else
	{
		if (stk_a->values[0] > midl_a)
			ft_rotate(stk_a, 'a');
		else
		{
			ft_swap_one(stk_a, 'a');
			ft_rotate(stk_a, 'a');
		}
	}
}

void	ft_sort_stack_a(t_stack *stk_a, t_stack *stk_b, int len)
{
	int	pivot_a;
	int	pivot_b;
	int	cnt;

	cnt = len / 2;
	pivot_a = ft_quick_pivot(stk_a->values, len, cnt);
	pivot_b = ft_quick_pivot(stk_a->values, len, 1);
	while (cnt)
		if (stk_a->values[0] < pivot_a)
		{
			ft_push(stk_b, stk_a, 'b');
			if (stk_b->values[0] < pivot_b)
				ft_rotate(stk_b, 'b');
			cnt--;
		}
		else
			ft_rotate(stk_a, 'a');
	pivot_a = ft_quick_pivot(stk_a->values, len, 1);
	ft_sort_a(stk_a, pivot_a);
	cnt = stk_b->top + 1;
	if (cnt == 2)
		ft_sort_two_stack_b(stk_a, stk_b);
	else
		ft_sort_three_stack_b(stk_a, stk_b, cnt);
}

void	ft_sort_three(t_stack *stk_a, int len)
{
	int	midl;

	midl = ft_quick_pivot(stk_a->values, len, 1);
	if (stk_a->values[0] == midl)
	{
		if (stk_a->values[1] < stk_a->values[2])
			ft_swap_one(stk_a, 'a');
		else
			ft_reverse_rotate(stk_a, 'a');
	}
	else if (stk_a->values[1] == midl && stk_a->values[0] > stk_a->values[2])
	{
		ft_rotate(stk_a, 'a');
		ft_swap_one(stk_a, 'a');
	}
	else
	{
		if (stk_a->values[0] < stk_a->values[1])
			ft_swap_one(stk_a, 'a');
		ft_rotate(stk_a, 'a');
	}
}
