/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:07:08 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/27 16:14:50 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* push worker- take the first element at the top of stack_y and put it at    */
/* the top of stack_x. Do nothing if the stack_y is empty.                    */
/* ************************************************************************** */
void	ft_push_worker(t_stack *stack_x, t_stack *stack_y, char *print_val)
{
	if (stack_y->top > 0)
	{
		stack_x->top++;
		stack_x->values[stack_x->top] = stack_y->values[stack_y->top];
		stack_y->top--;
		write(1, print_val, 3);
	}
}

/* ************************************************************************** */
/* push - take the first element at the top of one stack and put it at the    */
/* top of another stack. Do nothing if the first stack is empty.              */
/* ************************************************************************** */
void	ft_push(t_stack *stack_a, t_stack *stack_b, char name)
{
	char	print_val[3];

	print_val[0] = 'p';
	print_val[1] = name;
	print_val[2] = '\n';
	if (name == 'a')
		ft_push_worker(stack_a, stack_b, print_val);
	if (name == 'b')
		ft_push_worker(stack_b, stack_a, print_val);
	write(1, print_val, 3);
}
