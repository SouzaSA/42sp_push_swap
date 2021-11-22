/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:07:08 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 20:06:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

/* ************************************************************************** */
/* push - take the first element at the top of one stack and put it at the    */
/* top of another stack. Do nothing if the first stack is empty.              */
/* ************************************************************************** */
void	ft_push(t_vars *vars, char name)
{
	char	print_val[4];

	print_val[0] = 'p';
	print_val[1] = name;
	print_val[2] = '\n';
	print_val[3] = '\0';
	if (name == 'a')
		ft_push_worker(&vars->stk_a, &vars->stk_b);
	if (name == 'b')
		ft_push_worker(&vars->stk_b, &vars->stk_a);
	ft_lstadd_back(&vars->cmds, ft_lstnew(ft_strdup(print_val)));
}
