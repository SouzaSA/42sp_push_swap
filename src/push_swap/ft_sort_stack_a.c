/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:07:40 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/15 19:07:52 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void				sort_two_steck_a(long *a)
{
	if (a[0] > a[1])
		swap_a(a, TRUE);
}

static inline void	a0_equal_midl_a(long *a, long midl_a)
{
	if (a[1] < midl_a)
		swap_a(a, TRUE);
	else
	{
		rotate_a(a, TRUE);
		swap_a(a, TRUE);
		reverse_rotate_a(a, TRUE);
		swap_a(a, TRUE);
	}
}

static inline void	a1_equal_midl_a(long *a, long midl_a)
{
	if (a[0] > midl_a)
	{
		swap_a(a, TRUE);
		rotate_a(a, TRUE);
		swap_a(a, TRUE);
		reverse_rotate_a(a, TRUE);
		swap_a(a, TRUE);
	}
}

static inline void	a2_equal_midl_a(long *a, long midl_a)
{
	if (a[0] < midl_a)
	{
		rotate_a(a, TRUE);
		sort_two_steck_a(a);
		reverse_rotate_a(a, TRUE);
	}
	else
	{
		swap_a(a, TRUE);
		rotate_a(a, TRUE);
		swap_a(a, TRUE);
		reverse_rotate_a(a, TRUE);
	}
}

void				sort_three_steck_a(long *a, ssize_t len)
{
	long	midl_a;

	midl_a = quick_select(a, len, 1);
	if (a[0] == midl_a)
		a0_equal_midl_a(a, midl_a);
	else if (a[1] == midl_a)
		a1_equal_midl_a(a, midl_a);
	else
		a2_equal_midl_a(a, midl_a);
}
