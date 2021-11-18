/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_pivot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:06:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/18 15:55:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	qselect(int *array, int len, int k);
static void	ft_swap(int *array, int pos_a, int pos_b);

int	ft_quick_pivot(t_stack *stk, int len, int k)
{
	int	i;
	int	pivot;
	int	*tmp;

	tmp = (int *)malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		tmp[len - 1 - i] = stk->values[stk->top - i];
		i++;
	}
	pivot = qselect(tmp, len, k);
	free(tmp);
	return (pivot);
}

static int	qselect(int *array, int len, int k)
{
	int	i;
	int	mid;

	mid = 0;
	i = 0;
	while (i < (len - 1))
	{
		if (array[i] > array[len - 1])
		{
			i++;
			continue;
		}
		ft_swap(array, i, mid);
		i++;
		mid++;
	}
	ft_swap(array, len - 1, mid);
	if (k == mid)
		return (array[mid]);
	else if (mid > k)
		return (qselect(array, mid, k));
	else
		return (qselect(array + mid, len - mid, k - mid));
}

static void	ft_swap(int *array, int pos_a, int pos_b)
{
	int	tmp;

	tmp = array[pos_a];
	array[pos_a] = array[pos_b];
	array[pos_b] = tmp;
}
