/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:20:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/24 11:58:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* destroy stacks - free alloced memory on stacks values, and set top and     */
/* size to right values.                                                      */
/* ************************************************************************** */
void	ft_destroy_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = -1;
	stack_a->size = 0;
	free(stack_a->values);
	stack_b->top = -1;
	stack_b->size = 0;
	free(stack_b->values);
}
