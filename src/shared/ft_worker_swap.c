/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_worker_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:05:54 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 13:18:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

/* ************************************************************************** */
/* swap - swap the first 2 elements at the top of a stack. hardwork.          */
/* ************************************************************************** */
void	ft_swap_worker(t_stack *stack)
{
	int	tmp;

	tmp = stack->values[stack->top];
	stack->values[stack->top] = stack->values[stack->top - 1];
	stack->values[stack->top - 1] = tmp;
}
