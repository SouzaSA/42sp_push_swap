/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:21 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/18 15:14:25 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_partition(t_stack *stk_a, t_stack *stk_b, int pivot, int cnt_b);

void	ft_separate_stk_b(t_stack *stk_a, t_stack *stk_b, int blk_a, int *cnt_b)
{
	int	pivot;
	int	cnt;
	int	cnt_push_to_a;
	int	cnt_rotate_b;

	if (cnt_b[0] < 4)
	{
		if (cnt_b[0] == 1)
			ft_push(stk_a, stk_b, 'a');
		else if (cnt_b[0] == 2)
			ft_sort_two_stack_b(stk_a, stk_b);
		else if (cnt_b[0] == 3)
			ft_sort_three_stack_b(stk_a, stk_b, cnt_b[0]);
		return ;
	}
	blk_a = stk_a->values[0];
	cnt_push_to_a = cnt_b[0] / 2 - 1;
	if (cnt_b[0] % 2)
		cnt_push_to_a = cnt_b[0] / 2;
	pivot = ft_quick_pivot(stk_b, cnt_b[0], cnt_push_to_a);
	cnt_rotate_b = ft_partition(stk_a, stk_b, pivot, cnt_b[0]);
	ft_separate_stk_a(stk_a, stk_b, blk_a, 1);
	ft_reverse_rotate_both(stk_a, stk_b);
	cnt = 1;
	while (cnt_b[1] && cnt++ < cnt_rotate_b)
		ft_reverse_rotate(stk_b, 'b');
	cnt_b[0] = cnt_rotate_b;
	ft_separate_stk_b(stk_a, stk_b, stk_a->values[0], cnt_b);
}

static int	ft_partition(t_stack *stk_a, t_stack *stk_b, int pivot, int cnt_b)
{
	int	cnt_rotate_b;

	cnt_rotate_b = 0;
	while (cnt_b--)
		if (stk_b->values[0] > pivot)
			ft_push(stk_a, stk_b, 'a');
		else if (stk_b->values[0] == pivot)
		{
			ft_push(stk_a, stk_b, 'a');
			if (stk_b->values[0] < pivot && cnt_b)
			{
				ft_rotate_both(stk_a, stk_b);
				cnt_rotate_b++;
				cnt_b--;
			}
			else
				ft_rotate(stk_a, 'a');
		}
		else
		{
			ft_rotate(stk_b, 'b');
			cnt_rotate_b++;
		}
	return (cnt_rotate_b);
}
