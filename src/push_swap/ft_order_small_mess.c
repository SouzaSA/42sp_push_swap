/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_small_mess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:25:36 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/07 20:03:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_check_sort_stack_a(t_stack *stk_a);
static int	ft_check_partial_sort(t_stack *stk, char stk_name);
static void	ft_get_idxs(t_stack *stk, t_idxs *idx_stk, char stk_name);

void	ft_order_small_mess(t_stack *stk_a, t_stack *stk_b)
{
	int		mean_a;
	t_idxs	idxs_a;
	t_idxs	idxs_b;

	ft_get_idxs(stk_a, &idxs_a, 'a');
	mean_a = ft_average(stk_a->values[idxs_a.max], stk_a->values[idxs_a.max]);
	while (!ft_check_sort_stack_a(stk_a))
	{
		ft_get_idxs(stk_a, &idxs_a, 'a');
		ft_get_idxs(stk_b, &idxs_b, 'b');
		if (idxs_a.min <= stk_a->top / 2 && stk_b->top > 1 \
			&& idxs_b.max <= stk_b->top / 2)
			ft_rotate_both(stk_a, stk_b);
		else if (idxs_a.min > stk_a->top / 2 && stk_b->top > 1 \
			&& idxs_b.max > stk_b->top / 2 && !ft_check_partial_sort(stk_a, 'a') \
			&& !ft_check_partial_sort(stk_b, 'b'))
			ft_reverse_rotate_both(stk_a, stk_b);
		else if (idxs_a.min <= stk_a->top / 2 && !ft_check_partial_sort(stk_a, 'a'))
			ft_rotate(stk_a, 'a');
		else if (idxs_b.max <= stk_b->top / 2 && !ft_check_partial_sort(stk_b, 'b'))
			ft_rotate(stk_b, 'b');
		else if (idxs_a.min > stk_a->top / 2 && !ft_check_partial_sort(stk_a, 'a'))
			ft_reverse_rotate(stk_a, 'a');
		else if (idxs_a.max > stk_a->top / 2 && !ft_check_partial_sort(stk_b, 'b'))
			ft_reverse_rotate(stk_b, 'b');
		else if (stk_a->values[stk_a->top] > stk_a->values[stk_a->top - 1] \
			&& stk_b->values[stk_b->top] < stk_b->values[stk_b->top - 1])
			ft_swap_both(stk_a, stk_b);
		else if (stk_a->values[stk_a->top] > stk_a->values[stk_a->top - 1])
			ft_swap_one(stk_a, 'a');
		else if (stk_b->values[stk_b->top] < stk_b->values[stk_b->top - 1])
			ft_swap_one(stk_b, 'b');
	}
}

static int	ft_check_sort_stack_a(t_stack *stk_a)
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	if (stk_a->size > stk_a->top + 1)
		is_sorted = 0;
	while (is_sorted && i < (stk_a->size - 1))
	{
		if (stk_a->values[i] < stk_a->values[i + 1])
		is_sorted = 0;
		i++;
	}
	return (is_sorted);
}

static void	ft_get_idxs(t_stack *stk, t_idxs *idx_stk, char stk_name)
{
	int	i;
	int	find_flag;

	i = stk->top;
	find_flag = 0;
	idx_stk->min = ft_smallest_int_idx(stk->values, stk->top + 1);
	idx_stk->max = ft_largest_int_idx(stk->values, stk->top + 1);
	idx_stk->first_wrong = stk->top + 1;
	while (stk->top > 1 && i > 0)
	{
		if (!find_flag)
		{
			if (stk_name == 'a' && stk->values[i] > stk->values[i - 1])
				idx_stk->first_wrong = i;
			else if (stk_name == 'b' && stk->values[i] < stk->values[i - 1])
				idx_stk->first_wrong = i;
			if (idx_stk->first_wrong < stk->top + 1)
				find_flag = 1;
		}
		i--;
	}
}

static int	ft_check_partial_sort(t_stack *stk, char stk_name)
{
	int	i;
	int	is_ordered;

	i = stk->top;
	is_ordered = 1;
	while (i > 0)
	{
		if (stk_name == 'a' && stk->values[i] > stk->values[i - 1])
			is_ordered = 0;
		if (stk_name == 'b' && stk->values[i] < stk->values[i - 1])
			is_ordered = 0;
		i--;
	}
	return (is_ordered);
}
