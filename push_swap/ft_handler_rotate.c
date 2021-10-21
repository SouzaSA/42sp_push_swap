/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:08:02 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/20 18:20:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* rotate worker - shift up all elements of a stack by 1. The first element   */
/* becomes the last one.                                                      */
/* ************************************************************************** */
void	ft_rotate_worker(t_stack *stack)
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

/* ************************************************************************** */
/* rotate - shift up all elements of a stack by 1. The first element becomes  */
/* the last one. Print "ra" or "rb" message.                                  */
/* ************************************************************************** */
void	ft_rotate(t_stack *stack, char name)
{
	char	print_val[3];

	print_val[0] = 'r';
	print_val[1] = name;
	print_val[2] = '\n';
	ft_rotate_worker(stack);
	write(1, print_val, 3);
}

/* ************************************************************************** */
/* rotate both - shift up all elements of both stacks by 1. The first element */
/* becomes the last one, in both stacks. Print "rr".                          */
/* ************************************************************************** */
void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate_worker(stack_a);
	ft_rotate_worker(stack_b);
	write(1, "rr", 3);
}
