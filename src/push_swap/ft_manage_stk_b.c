/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stk_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:21 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/15 19:10:17 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int			partition(long *a, long *b, long midl_b, ssize_t cnt_b)
{
	ssize_t		cnt_rotate_b;

	cnt_rotate_b = 0;
	while (cnt_b--)
		if (midl_b < b[0])
			push_a(a, b, TRUE);
		else if (midl_b == b[0])
		{
			push_a(a, b, TRUE);
			if (midl_b > b[0] && cnt_b)
			{
				rotate_rotate(a, b, TRUE);
				cnt_rotate_b++;
				cnt_b--;
			}
			else
				rotate_a(a, TRUE);
		}
		else
		{
			rotate_b(b, TRUE);
			cnt_rotate_b++;
		}
	return (cnt_rotate_b);
}

void	separation_steck_b(long *a, long *b, long block_a, ssize_t *cnt_b)
{
	long		midl_b;
	ssize_t		cnt;
	ssize_t		cnt_push_to_a;
	ssize_t		cnt_rotate_b;

	if (cnt_b[0] < 4)
	{
		if (cnt_b == 1)
			push_a(a, b, TRUE);
		else if (cnt_b == 2)
			sort_two_steck_b(a, b);
		else if (cnt_b == 3)
			sort_three_steck_b(a, b, cnt_b);
		return ;
	}
	block_a = a[0];
	cnt_push_to_a = cnt_b[0] / 2 - 1;
	cnt_push_to_a = cnt_b[0] % 2 ? cnt_b[0] / 2 : ;
	midl_b = quick_select(b, cnt_b[0], cnt_push_to_a);
	cnt_rotate_b = 0;
	cnt_rotate_b = partition(a, b, midl_b, cnt_b[0]);
	separation_steck_a(a, b, block_a, TRUE);
	reverse_rotate_rotate(a, b, TRUE);
	cnt = 1;
	while (cnt_b[1] && cnt++ < cnt_rotate_b)
		reverse_rotate_b(b, TRUE);
	cnt_b[0] = cnt_rotate_b;
	separation_steck_b(a, b, a[0], cnt_b);
}
