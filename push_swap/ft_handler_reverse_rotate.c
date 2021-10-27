/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:09:39 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/27 16:40:44 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* reverse rotate worker - shift down all elements of a stack by 1. The last  */
/* element becomes the first one                                              */
/* ************************************************************************** */
void	ft_reverse_rotate_worker(t_stack *stack)
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

/* ************************************************************************** */
/* reverse rotate - shift down all elements of a stack by 1. The last element */
/* becomes the first one. Print "rra" or "rrb" message.                       */
/* ************************************************************************** */
void	ft_reverse_rotate(t_stack *stack, char name)
{
	char	print_val[4];

	print_val[0] = 'r';
	print_val[1] = 'r';
	print_val[2] = name;
	print_val[3] = '\n';
	ft_reverse_rotate_worker(stack);
	write(1, print_val, 4);
}

/* ************************************************************************** */
/* rotate both - shift down all elements of both stacks by 1. The last        */
/* element becomes the first one, in both stacks. Print "rrr".                */
/* ************************************************************************** */
void	ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate_worker(stack_a);
	ft_reverse_rotate_worker(stack_b);
	write(1, "rrr", 3);
}
