/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/27 15:37:39 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	*ft_get_distances(t_stack *stack);

int	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int	max_idx;
	int	*distances;

	i = 0;
	distances = ft_get_distances(stack_a);

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

static int	ft_check_sort_a(t_stack *stack_a)
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	if (stack_a->size > stack_a->top + 1)
		is_sorted = 0;
	while (is_sorted && i < stack_a->size - 1)
	{
		if (stack_a->values[i] < stack_a->values[i + 1])
		is_sorted = 0;
		i++;
	}
	return (is_sorted);
}
