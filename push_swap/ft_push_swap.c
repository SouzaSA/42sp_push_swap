/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/28 16:58:01 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	*ft_get_distances_a(t_stack *stack);
static int	ft_check_sort_stack_a(t_stack *stk_a);

int	ft_push_swap(t_stack *stk_a, t_stack *stk_b)
{
	int i;
	int	max_idx;
	int	*distances_a;
	int	*distances_b;

	i = 0;
	while (!ft_check_sort_stack_a(stk_a))
	{
		distances_a = ft_get_distances_a(stk_a);
		if (stk_a->values[stk_a->top] == stk_a->values[stk_a->top - 1] - 1)
			ft_swap_one(stk_a, 'a');
		else if (distances_a[stk_a->top] == 0 && stk_a->values[stk_a->top] < stk_a->size / 2)
			ft_push(stk_a, stk_b, 'b');
		else if (distances_a[stk_a->top] == 1)
			ft_rotate(stk_a, 'a');
		else if (distances_a[stk_a->top] == -1)
			ft_reverse_rotate(stk_a, 'a');
		else if (stk_a->values[stk_a->top] < stk_a->size / 2)
			ft_push(stk_a, stk_b, 'b');

	}
	free(distances_a);
	free(distances_b);
	return (0);
}

static int	*ft_get_distances_a(t_stack *stack)
{
	int i;
	int	*distances_a;

	i = 0;
	distances_a = (int *)malloc(stack->size * sizeof(int));
	while (i < stack->size)
	{
		distances_a[i] = stack->values[i] - i;
		if (ft_abs(distances_a[i]) > (stack->top + 1) / 2)
			distances_a[i] = -1 * (stack->top + 1 + distances_a[i]) % (stack->top + 1);
		i++;
	}
	return (distances_a);
}

void ft_load_distances(t_stack *stack, char stack_name)
{
	int i;
	int	*distances;

	i = 0;
	distances = (int *)malloc(stack->size * sizeof(int));
	while (i < stack->size)
	{
		distances[i] = stack->values[i] - i;
		if (ft_abs(distances[i]) > (stack->top + 1) / 2)
			distances[i] = -1 * (stack->top + 1 + distances[i]) % (stack->top + 1);
		i++;
	}
	return (distances);
}

static int	*ft_get_distances_b(t_stack *stack)
{
	int i;
	int	*distances_b;

	i = 0;
	distances_b = (int *)malloc(stack->size * sizeof(int));
	while (i < stack->size)
	{
		distances_b[i] = i - stack->values[i];
		if (distances_b[i] > (stack->top + 1) / 2)
			distances_b[i] -= (stack->top + 1);
		i++;
	}
	return (distances_b);
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
