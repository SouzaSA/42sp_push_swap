/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_big_mess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:25:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/09 16:15:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_check_sort_stack_a(t_stack *stk_a);
static int	ft_check_partial_sort(t_stack *stk, char stk_name);
static void	ft_get_idxs(t_stack *stk, t_idxs *idx_stk, char stk_name, int fwp);

void	ft_order_big_mess(t_stack *stk_a, t_stack *stk_b)
{
	int		mean_a;
	t_idxs	idxs_a;
	t_idxs	idxs_b;

	ft_get_idxs(stk_a, &idxs_a, 'a', 0);
	ft_get_idxs(stk_b, &idxs_b, 'b', 0);
	mean_a = ft_average(stk_a->values[idxs_a.max], stk_a->values[idxs_a.min]);
	while (!ft_check_sort_stack_a(stk_a))
	{
		ft_get_idxs(stk_a, &idxs_a, 'a', idxs_a.first_wrong);
		ft_get_idxs(stk_b, &idxs_b, 'b', idxs_b.first_wrong);
		if (stk_a->top > stk_a->size / 2 && stk_a->values[stk_a->top] < mean_a \
			&& idxs_a.first_wrong != 0 && !ft_check_partial_sort(stk_a, 'a'))
		{
			ft_push(stk_a, stk_b, 'b');
			idxs_a.first_wrong = 0;
		}
		else if (idxs_a.max != stk_a->top && idxs_b.min != stk_b->top \
			&& stk_a->values[stk_a->top] > stk_a->values[stk_a->top - 1] \
			&& stk_b->top > 0 && stk_b->values[stk_b->top] < stk_b->values[stk_b->top - 1])
			ft_swap_both(stk_a, stk_b);
		else if (idxs_a.max != stk_a->top && stk_a->values[stk_a->top] > stk_a->values[stk_a->top - 1])
			ft_swap_one(stk_a, 'a');
		else if (idxs_b.min != stk_b->top && stk_b->values[stk_b->top] < stk_b->values[stk_b->top - 1] && stk_b->top > 0)
			ft_swap_one(stk_b, 'b');
		else if (!ft_check_partial_sort(stk_a, 'a') && !ft_check_partial_sort(stk_b, 'b') && idxs_a.first_wrong > 0 && idxs_a.first_wrong >= stk_a->top / 2 && stk_b->top > 1 \
			&& idxs_b.first_wrong >= stk_b->top / 2 && idxs_a.first_wrong > 0)
		{
			ft_rotate_both(stk_a, stk_b);
			idxs_a.first_wrong = (idxs_a.first_wrong - 1 + stk_a->top + 1) % (stk_a->top + 1);
			idxs_b.first_wrong = (idxs_b.first_wrong - 1 + stk_b->top + 1) % (stk_b->top + 1);
		}
		else if (!ft_check_partial_sort(stk_a, 'a') && !ft_check_partial_sort(stk_b, 'b') && idxs_a.first_wrong < stk_a->top / 2 && idxs_a.first_wrong > 0 && stk_b->top > 1 \
			&& idxs_b.first_wrong < stk_b->top / 2 && idxs_a.first_wrong > 0)
		{
			ft_reverse_rotate_both(stk_a, stk_b);
			idxs_a.first_wrong = (idxs_a.first_wrong + 1) % (stk_a->top + 1);
			idxs_b.first_wrong = (idxs_b.first_wrong + 1) % (stk_b->top + 1);
		}
		else if (!ft_check_partial_sort(stk_a, 'a') && idxs_a.first_wrong >= stk_a->top / 2 && idxs_a.first_wrong > 0)
		{
			ft_rotate(stk_a, 'a');
			idxs_a.first_wrong = (idxs_a.first_wrong - 1 + stk_a->top + 1) % (stk_a->top + 1);
		}
		else if (!ft_check_partial_sort(stk_b, 'b') && idxs_b.first_wrong >= stk_b->top / 2 && idxs_a.first_wrong > 0)
		{
			ft_rotate(stk_b, 'b');
			idxs_b.first_wrong = (idxs_b.first_wrong - 1 + stk_b->top + 1) % (stk_b->top + 1);
		}
		else if (!ft_check_partial_sort(stk_a, 'a') && idxs_a.first_wrong < stk_a->top / 2 && idxs_a.first_wrong > 0)
		{
			ft_reverse_rotate(stk_a, 'a');
			idxs_a.first_wrong = (idxs_a.first_wrong + 1) % (stk_a->top + 1);
		}
		else if (!ft_check_partial_sort(stk_b, 'b') && idxs_a.first_wrong > 0 \
			&& idxs_b.first_wrong < stk_b->top / 2)
		{
			ft_reverse_rotate(stk_b, 'b');
			idxs_b.first_wrong = (idxs_b.first_wrong + 1) % (stk_b->top + 1);
		}
		else if (idxs_a.max == stk_a->top && idxs_b.min == stk_b->top && stk_a->top > 0 && stk_b->top > 0)
			ft_rotate_both(stk_a, stk_b);
		else if (idxs_a.max == stk_a->top && stk_a->top > 0)
			ft_rotate(stk_a, 'a');
		else if (idxs_b.min == stk_b->top && stk_b->top > 0)
			ft_rotate(stk_b, 'b');
		else if (ft_check_partial_sort(stk_a, 'a'))
			ft_push(stk_a, stk_b, 'a');
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
	while (is_sorted && i < stk_a->size - 1)
	{
		if (stk_a->values[i] < stk_a->values[i + 1])
			is_sorted = 0;
		i++;
	}
	return (is_sorted);
}

static void	ft_get_idxs(t_stack *stk, t_idxs *idx_stk, char stk_name, int fwp)
{
	int	i;
	int	find_flag;

	i = stk->top;
	find_flag = 0;
	idx_stk->min = ft_smallest_int_idx(stk->values, stk->top + 1);
	idx_stk->max = ft_largest_int_idx(stk->values, stk->top + 1);
	idx_stk->first_wrong = fwp;
	if (fwp == 0)
		idx_stk->first_wrong = stk->top + 1;
	while (fwp == 0 && stk->top > 1 && i > 0)
	{
		if (!find_flag)
		{
			if (stk_name == 'a' && stk->values[i] > stk->values[i - 1])
				idx_stk->first_wrong = i + 1;
			else if (stk_name == 'b' && stk->values[i] < stk->values[i - 1])
				idx_stk->first_wrong = i + 1;
			if (idx_stk->first_wrong < stk->top + 1)
				find_flag = 1;
		}
		i--;
	}
	if (!find_flag)
		idx_stk->first_wrong = 0;
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
