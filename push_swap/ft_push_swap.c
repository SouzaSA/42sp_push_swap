/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/27 16:54:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	*ft_get_distances(t_stack *stack);
static int	ft_check_sort_stack_a(t_stack *stk_a);

int	ft_push_swap(t_stack *stk_a, t_stack *stk_b)
{
	int i;
	int	max_idx;
	int	*distances;

	i = 0;
	while (!ft_check_sort_stack_a(stk_a))
	{
		distances = ft_get_distances(stk_a);
		if (stk_a->values[stk_a->top] == stk_a->values[stk_a->top - 1] - 1)
			ft_swap_one(stk_a, 'a');
		else if (distances[stk_a->top] == 0 && stk_a->values[stk_a->top] < stk_a->size / 2)
			ft_push(stk_a, stk_b, 'b');
		else if (distances[stk_a->top] == 1)
			ft_rotate(stk_a, 'a');
		else if (distances[stk_a->top] == -1)
			ft_reverse_rotate(stk_a, 'a');
		else if (stk_a->values[stk_a->top] < stk_a->size / 2)
			ft_push(stk_a, stk_b, 'b');
	}

	return (0);
}

static int	*ft_get_distances(t_stack *stack)
{
	int i;
	int	*distances;

	i = 0;
	distances = (int *)malloc(stack->size * sizeof(int));
	while (i < stack->size)
	{
		distances[i] = i - stack->values[i];
		if (distances[i] > (stack->top + 1) / 2)
			distances[i] -= (stack->top + 1);
		i++;
	}
	return (distances);
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
