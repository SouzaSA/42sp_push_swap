/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:21 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/16 16:35:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	partition(t_stack *stk_a, t_stack *stk_b, int midl_b, int cnt_b);

static int	partition(t_stack *stk_a, t_stack *stk_b, int midl_b, int cnt_b)
{
	int	cnt_rotate_b;

	cnt_rotate_b = 0;
	while (cnt_b--)
		if (stk_b->values[0] > midl_b)
			ft_push(stk_a, stk_b, 'a');
		else if (stk_b->values[0] == midl_b)
		{
			ft_push(stk_a, stk_b, 'a');
			if (stk_b->values[0] < midl_b && cnt_b)
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

void	ft_separation_stack_b(t_stack *stk_a, t_stack *stk_b, int block_a, int *cnt_b)
{
	int	midl_b;
	int	cnt;
	int	cnt_push_to_a;
	int	cnt_rotate_b;

	if (cnt_b[0] < 4)
	{
		if (cnt_b == 1)
			ft_push(stk_a, stk_b, 'a');
		else if (cnt_b == 2)
			ft_sort_two_stack_b(stk_a, stk_b);
		else if (cnt_b == 3)
			ft_sort_three_stack_b(stk_a, stk_b, cnt_b);
		return ;
	}
	block_a = stk_a->values[0];
	cnt_push_to_a = cnt_b[0] / 2 - 1;
	if (cnt_b[0] % 2)
		cnt_push_to_a = cnt_b[0] / 2;
	midl_b = quick_pivot(stk_b, cnt_b[0], cnt_push_to_a);
	cnt_rotate_b = 0;
	cnt_rotate_b = partition(stk_a, stk_b, midl_b, cnt_b[0]);
	separation_stack_a(a, b, block_a, TRUE);
	reverse_rotate_rotate(a, b, TRUE);
	cnt = 1;
	while (cnt_b[1] && cnt++ < cnt_rotate_b)
		reverse_rotate_b(b, TRUE);
	cnt_b[0] = cnt_rotate_b;
	separation_stack_b(a, b, a[0], cnt_b);
}
