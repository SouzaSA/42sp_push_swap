/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_worker_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:09:18 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 13:18:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

/* ************************************************************************** */
/* reverse rotate worker - shift down all elements of a stack by 1. The last  */
/* element becomes the first one                                              */
/* ************************************************************************** */
void	ft_reverse_rotate_worker(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < stack->top)
	{
		tmp = stack->values[i + 1];
		stack->values[i + 1] = stack->values[i];
		stack->values[i] = tmp;
		i++;
	}
}
