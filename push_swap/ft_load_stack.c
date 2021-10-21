/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:20:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/20 19:35:28 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* load - load the stacks and alloc memory to values arrays a and b set stack */
/* size and set top index value, -1 is for empty stack.                       */
/* ************************************************************************** */
void	ft_load(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	stack_b->size = argc - 1;
	stack_b->top = -1;
	stack_b->values = malloc(stack_b->size * sizeof(t_stack));
	stack_a->values = malloc(stack_a->size * sizeof(t_stack));
	stack_a->size = argc - 1;
	while (i < stack_a->size)
	{
		stack_a->values[i] = argv[i + 1];
		i++;
	}
}