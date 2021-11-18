/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:30:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/18 15:36:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_partition(t_stack *stk_a, t_stack *stk_b, int push_to_b, int *i);
static void	ft_push_to_stack_a(t_stack *stk_a, t_stack *stk_b, int pivot_a);
static int	ft_more_three(t_stack *stk_a, t_stack *stk_b, int *cnt, int pivot);

void	ft_separate_stk_a(t_stack *stk_a, t_stack *stk_b, int blk, int flag)
{
	int	flag_b;
	int	len_blk_a;
	int	i[2];
	int	push_to_b[2];

	len_blk_a = blk;
	if (len_blk_a < 4)
	{
		if (len_blk_a == 2)
			ft_sort_two_stack_a(stk_a);
		else if (len_blk_a == 3)
			ft_sort_three_stack_a(stk_a, len_blk_a);
		return ;
	}
	push_to_b[0] = len_blk_a / 2;
	if (len_blk_a % 2)
		push_to_b[0] = len_blk_a / 2 + 1;
	i[0] = ft_quick_pivot(stk_a, len_blk_a, push_to_b[0]);
	i[1] = flag;
	flag_b = ft_partition(stk_a, stk_b, push_to_b[0], i);
	ft_separate_stk_a(stk_a, stk_b, stk_a->top + 1, flag);
	if (flag_b)
		ft_push_to_stack_a(stk_a, stk_b, i[0]);
	if (push_to_b[0] != stk_b->top + 1)
	{
		push_to_b[1] = 1;
		ft_separate_stk_b(stk_a, stk_b, stk_a->top + 1, push_to_b);
	}
	else
	{
		push_to_b[1] = 0;
		ft_separate_stk_b(stk_a, stk_b, blk, push_to_b);
	}
}

static int	ft_partition(t_stack *stk_a, t_stack *stk_b, int push_to_b, int *i)
{
	int	flag;
	int	less_three;
	int	cnt_rotate_a;

	cnt_rotate_a = 0;
	flag = 0;
	less_three = 1;
	if (push_to_b > 3)
		less_three = 0;
	while (push_to_b)
		if (stk_a->values[stk_a->top] < i[0])
		{
			ft_push(stk_a, stk_b, 'b');
			push_to_b--;
		}
		else if (!less_three && stk_a->values[stk_a->top] == i[0])
			flag = ft_more_three(stk_a, stk_b, &cnt_rotate_a, i[0]);
		else
		{
			ft_rotate(stk_a, 'a');
			cnt_rotate_a++;
		}
	while (i[1] && cnt_rotate_a--)
		ft_reverse_rotate(stk_a, 'a');
	return (flag);
}

static void	ft_push_to_stack_a(t_stack *stk_a, t_stack *stk_b, int pivot_a)
{
	if (pivot_a == stk_b->values[stk_b->top])
	{
		ft_reverse_rotate(stk_b, 'b');
		ft_push(stk_a, stk_b, 'a');
	}
}

static int	ft_more_three(t_stack *stk_a, t_stack *stk_b, int *cnt, int pivot)
{
	ft_push(stk_a, stk_b, 'b');
	if (stk_a->values[stk_b->top] > pivot)
	{
		ft_rotate_both(stk_a, stk_b);
		(*cnt)++;
	}
	else
		ft_rotate(stk_b, 'b');
	return (1);
}
