/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_worker_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:03:18 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 13:04:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

/* ************************************************************************** */
/* push worker- take the first element at the top of stack_y and put it at    */
/* the top of stack_x. Do nothing if the stack_y is empty.                    */
/* ************************************************************************** */
void	ft_push_worker(t_stack *stack_x, t_stack *stack_y)
{
	if (stack_y->top >= 0)
	{
		stack_x->top++;
		stack_x->values[stack_x->top] = stack_y->values[stack_y->top];
		stack_y->top--;
	}
}
