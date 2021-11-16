/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:30:07 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/15 19:06:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static inline int	more_three(long *a, long *b, ssize_t *cnt, long midl)
{
	push_b(b, a, TRUE);
	if (a[0] > midl)
	{
		rotate_rotate(a, b, TRUE);
		(*cnt)++;
	}
	else
		rotate_b(b, TRUE);
	return (TRUE);
}

static int			partition(long *a, long *b, ssize_t cnt_push_to_b, long *i)
{
	int			flag;
	int			less_three;
	ssize_t		cnt_rotate_a;

	cnt_rotate_a = 0;
	flag = FALSE;
	less_three = cnt_push_to_b > 3 ? FALSE : TRUE;
	while (cnt_push_to_b)
		if (a[0] < i[0])
		{
			push_b(b, a, TRUE);
			cnt_push_to_b--;
		}
		else if (!less_three && a[0] == i[0])
			flag = more_three(a, b, &cnt_rotate_a, i[0]);
		else
		{
			rotate_a(a, TRUE);
			cnt_rotate_a++;
		}
	while (i[1] && cnt_rotate_a--)
		reverse_rotate_a(a, TRUE);
	return (flag);
}

static void			push_block_to_steck_a(long *a, long *b, long midl_a)
{
	ssize_t		len_b;

	len_b = len_stack(b, END) - 1;
	if (midl_a == b[len_b])
	{
		reverse_rotate_b(b, TRUE);
		push_a(a, b, TRUE);
	}
}

void	separation_steck_a(t_stack *stk_a, t_stack *stk_b, long len, int flag)
{
	int			flag_b;
	ssize_t		len_a;
	long		i[2];
	long		cnt_push_to_b[2];

	if (stk_a->top < 3)
	{
		if (stk_a->top == 1)
			sort_two_steck_a(stk_a);
		else if (stk_a->top == 2)
			sort_three_steck_a(stk_a);
		return ;
	}
	cnt_push_to_b[0] = (stk_a->top + 1) / 2;
	if ((stk_a->top + 1) % 2)
		cnt_push_to_b[0] = (stk_a->top + 1) / 2 + 1;
	i[0] = quick_select(a, (stk_a->top + 1), cnt_push_to_b[0]);
	i[1] = flag;
	flag_b = partition(a, b, cnt_push_to_b[0], i);
	separation_steck_a(a, b, block, flag);
	if (flag_b)
		push_block_to_steck_a(a, b, i[0]);
	if (cnt_push_to_b[0] != len_stack(b, END))
	{
		cnt_push_to_b[1] = TRUE;
		separation_steck_b(a, b, len, cnt_push_to_b);
	}
	else
	{
		cnt_push_to_b[1] = FALSE;
		separation_steck_b(a, b, len, cnt_push_to_b);
	}
}
