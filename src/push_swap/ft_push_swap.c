/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/03 20:21:58 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h> //tirar

static int	*ft_get_distances(t_stack *stk, char stack_name);
static int	ft_check_sort_stack_a(t_stack *stk_a);
static int	ft_get_first_non_zero_idx(int *distances, int size);
static void	ft_update_distances(t_stack *stk, int *distances, char stack_name);

int	ft_push_swap(t_stack *stk_a, t_stack *stk_b)
{
	int	*distances_a;
	int	*distances_b;

	distances_a = ft_get_distances(stk_a, 'a');
	distances_b = ft_get_distances(stk_b, 'a');
	while (!ft_check_sort_stack_a(stk_a))
	{
		if (stk_a->values[stk_a->top] == stk_a->values[stk_a->top - 1] + 1)
			ft_swap_one(stk_a, 'a');
		else if (distances_a[stk_a->top] == 0 && stk_a->values[stk_a->top] < stk_a->size / 2 && ft_get_first_non_zero_idx(distances_a, stk_a->top + 1) < stk_a->top + 1)
			ft_push(stk_a, stk_b, 'b');
		else if (stk_a->values[stk_a->top] < stk_a->size / 2 && ft_get_first_non_zero_idx(distances_a, stk_a->top + 1) < stk_a->top + 1)
			ft_push(stk_a, stk_b, 'b');
		else if (stk_b->top > 0 && stk_b->values[stk_b->top] == stk_b->values[stk_b->top - 1] - 1)
			ft_swap_one(stk_b, 'b');
		else if (distances_a[stk_a->top] > 0 && ft_get_first_non_zero_idx(distances_a, stk_a->top + 1) < stk_a->top + 1)
			ft_rotate(stk_a, 'a');
		else if (distances_a[stk_a->top] < 0 && ft_get_first_non_zero_idx(distances_a, stk_a->top + 1) < stk_a->top + 1)
			ft_reverse_rotate(stk_a, 'a');
		else if (ft_get_first_non_zero_idx(distances_a, stk_a->top + 1) < stk_a->size / 2 && ft_get_first_non_zero_idx(distances_a, stk_a->top + 1) < stk_a->top + 1)
			ft_reverse_rotate(stk_a, 'a');
		else if (ft_get_first_non_zero_idx(distances_a, stk_a->top + 1) > stk_a->size / 2 && ft_get_first_non_zero_idx(distances_a, stk_a->top + 1) < stk_a->top + 1)
			ft_rotate(stk_a, 'a');
		else if (distances_b[stk_b->top] > 0 && ft_get_first_non_zero_idx(distances_b, stk_b->top + 1) < stk_b->top + 1)
			ft_rotate(stk_b, 'b');
		else if (distances_b[stk_b->top] < 0 && ft_get_first_non_zero_idx(distances_b, stk_b->top + 1) < stk_b->top + 1)
			ft_reverse_rotate(stk_b, 'b');
		else if (ft_get_first_non_zero_idx(distances_b, stk_b->top + 1) < stk_b->size / 2 && ft_get_first_non_zero_idx(distances_b, stk_b->top + 1) < stk_b->top + 1)
			ft_reverse_rotate(stk_b, 'b');
		else if (ft_get_first_non_zero_idx(distances_b, stk_b->top + 1) > stk_b->size / 2 && ft_get_first_non_zero_idx(distances_b, stk_b->top + 1) < stk_b->top + 1)
			ft_rotate(stk_b, 'b');
		else if (ft_get_first_non_zero_idx(distances_b, stk_b->top + 1) == stk_b->top + 1)
			ft_push(stk_a, stk_b, 'a');
		ft_update_distances(stk_a, distances_a, 'a');
		ft_update_distances(stk_b, distances_b, 'b');
	}
	free(distances_a);
	free(distances_b);
	return (0);
}

static int	*ft_get_distances(t_stack *stk, char stack_name)
{
	int i;
	int	*distances;

	i = 0;
	distances = (int *)malloc(stk->size * sizeof(int));
	while (i < stk->size)
	{
		distances[i] = 0;
		i++;
	}
	if (distances)
		ft_update_distances(stk, distances, stack_name);
	return (distances);
}


static void	ft_update_distances(t_stack *stk, int *distances, char stack_name)
{
	int i;
	int	stk_corrector;
	int clkwise;
	int	c_clkwise;

	i = 0;
	while (i < stk->top + 1)
	{
		stk_corrector = (stk->top + 1) - (stk->size - 1) + i + stk->values[i];
		if (stack_name == 'b')
			stk_corrector = (stk->top + 1) - i + stk->values[i];
		clkwise = (stk_corrector) % (stk->top + 1);
		c_clkwise = (stk->top + 1 - clkwise) % (stk->top + 1);
		if (clkwise < c_clkwise)
			distances[i] = clkwise;
		else
			distances[i] = -1 * c_clkwise;
		i++;
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

static int	ft_get_first_non_zero_idx(int *distances, int size)
{
	int	i;

	i = 0;
	while (distances && distances[i] == 0 && i < size)
		i++;
	return (i);
}
