/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:25:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/14 22:38:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static int	ft_has_small_pivot(t_stack *stk_a, int pivot, int part_size);
void	ft_manage_b(t_stack *stk_a, t_stack *stk_b, int size);
static int	ft_has_big_pivot(t_stack *stk_a, int pivot, int part_size);
void ft_order_three_or_less_b(t_stack *stk_a, t_stack *stk_b, int size);

void	ft_manage_a(t_stack *stk_a, t_stack *stk_b, int size)
{
	int i;
	int	pivot;
	int	part_size;

	i = 0;
	if (size <= 2)
	{
		if (size > 1 && stk_a->values[stk_a->top] > stk_a->values[stk_a->top - 1])
			ft_swap_one(stk_a, 'a');
		return ;
	}
	pivot = stk_a->values[stk_a->top];
	part_size = 0;
	while (ft_has_small_pivot(stk_a, pivot, size - i))
	{
		if (stk_a->values[stk_a->top] <= pivot)
		{
			ft_push(stk_a, stk_b, 'b');
			part_size++;
		}
		else
			ft_rotate(stk_a, 'a');
		i++;
	}
	//printf("a size: %d part_size: %d\n", size, part_size); //tirar
	ft_manage_b(stk_a, stk_b, part_size);
	ft_manage_a(stk_a, stk_b, size - part_size);
}

static int	ft_has_small_pivot(t_stack *stk_a, int pivot, int part_size)
{
	int	i;
	int	has_small;

	i = 0;
	has_small = 0;
	while (i < part_size)
	{
		if (stk_a->values[stk_a->top - i] <= pivot)
		{
			has_small = 1;
			break;
		}
		i++;
	}
	return (has_small);
}

void	ft_manage_b(t_stack *stk_a, t_stack *stk_b, int size)
{
	int	i;
	int	pivot;
	int	part_size;

	if (size <= 0)
		return ;
	i = 0;
	pivot = stk_b->values[stk_b->top];
	part_size = 0;
	if (size <= 3)
	{
		ft_order_three_or_less_b(stk_a, stk_b, size);
		while (i < size && !ft_is_ordered(stk_a->values, stk_a->size))
		{
			ft_rotate(stk_a, 'a');
			i++;
		}
		return ;
	}
	i = 0;
	while (ft_has_big_pivot(stk_b, pivot, size - i))
	{
		if (stk_b->values[stk_b->top] >= pivot)
		{
			ft_push(stk_a, stk_b, 'a');
			part_size++;
		}
		else
			ft_rotate(stk_b, 'b');
		i++;
	}
	//printf("b size: %d part_size: %d\n", size, part_size); //tirar
	ft_manage_b(stk_a, stk_b, size - part_size);
	ft_manage_a(stk_a, stk_b, part_size);
}

static int	ft_has_big_pivot(t_stack *stk_b, int pivot, int part_size)
{
	int	i;
	int	has_big;

	i = 0;
	has_big = 0;
	while (i < part_size)
	{
		if (stk_b->values[stk_b->top - i] >= pivot)
		{
			has_big = 1;
			break;
		}
		i++;
	}
	return (has_big);
}

void ft_order_three_or_less_b(t_stack *stk_a, t_stack *stk_b, int size)
{
	int	max;

	while (stk_b->top >= 0)
	{
		max = ft_largest_int_idx(stk_b->values, size);
		if (stk_b->top == max)
		{
			ft_push(stk_a, stk_b, 'a');
			size--;
		}
		else if (stk_b->top > 0 && stk_b->values[stk_b->top] < stk_b->values[stk_b->top - 1])
			ft_swap_one(stk_b, 'b');
		else
			ft_reverse_rotate(stk_b, 'b');
	}
}
