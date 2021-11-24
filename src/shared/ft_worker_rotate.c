/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_worker_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:08:00 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 13:18:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

/* ************************************************************************** */
/* rotate worker - shift up all elements of a stack by 1. The first element   */
/* becomes the last one.                                                      */
/* ************************************************************************** */
void	ft_rotate_worker(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->top;
	while (i > 0)
	{
		tmp = stack->values[i];
		stack->values[i] = stack->values[i - 1];
		stack->values[i - 1] = tmp;
		i--;
	}
}
