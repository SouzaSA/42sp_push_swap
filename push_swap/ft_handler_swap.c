/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:05:49 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/20 18:20:49 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* swap - swap the first 2 elements at the top of a stack. hardwork.          */
/* ************************************************************************** */
void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->values[stack->top];
	stack->values[stack->top] = stack->values[stack->top - 1];
	stack->values[stack->top - 1] = tmp;
}

/* ************************************************************************** */
/* swap one - swap the first 2 elements at the top of a stack. Do nothing if  */
/* there is only one or no elements. Name refers to to wich stack is in use.  */
/* ************************************************************************** */
void	ft_swap_one(t_stack *stack, char name)
{
	char	print_val[3];

	if (stack->top > 0)
	{
		print_val[0] = 's';
		print_val[1] = name;
		print_val[2] = '\n';
		ft_swap(stack);
		write(1, print_val, 3);
	}
}

/* ************************************************************************** */
/* swap both - swap the first 2 elements at the top of both stacks at same    */
/* time.                                                                      */
/* ************************************************************************** */
void	ft_swap_both(t_stack *stack_a, t_stack *stack_a)
{
	int	tmp;

	if (stack_a->top > 0 && stack_b->top > 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		write(1, "ss\n", 3);
	}
}
