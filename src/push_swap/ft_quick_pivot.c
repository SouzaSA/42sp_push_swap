/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_pivot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:06:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 16:20:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	qselect(int *array, int len, int stop);
static void	ft_swap(int *array, int pos_a, int pos_b);

int	ft_quick_pivot(t_stack *stk, int len, int stop)
{
	int	i;
	int	pivot;
	int	*tmp;

	tmp = (int *)malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		tmp[i] = stk->values[stk->top - i];
		i++;
	}
	pivot = qselect(tmp, len, stop);
	free(tmp);
	return (pivot);
}

static int	qselect(int *array, int len, int stop)
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
			continue ;
		}
		ft_swap(array, i, mid);
		i++;
		mid++;
	}
	ft_swap(array, len - 1, mid);
	if (stop == mid)
		return (array[mid]);
	else if (mid > stop)
		return (qselect(array, mid, stop));
	else
		return (qselect(array + mid, len - mid, stop - mid));
}

static void	ft_swap(int *array, int pos_a, int pos_b)
{
	int	tmp;

	tmp = array[pos_a];
	array[pos_a] = array[pos_b];
	array[pos_b] = tmp;
}
