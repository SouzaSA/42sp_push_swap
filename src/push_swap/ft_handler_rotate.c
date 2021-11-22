/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:08:02 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 20:06:51 by sde-alva         ###   ########.fr       */
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
/* rotate - shift up all elements of a stack by 1. The first element becomes  */
/* the last one. Print "ra" or "rb" message.                                  */
/* ************************************************************************** */
void	ft_rotate(t_stack *stack, char name, t_list **cmds)
{
	char	print_val[4];

	print_val[0] = 'r';
	print_val[1] = name;
	print_val[2] = '\n';
	print_val[3] = '\0';
	ft_rotate_worker(stack);
	ft_lstadd_back(cmds, ft_lstnew(ft_strdup(print_val)));
}

/* ************************************************************************** */
/* rotate both - shift up all elements of both stacks by 1. The first element */
/* becomes the last one, in both stacks. Print "rr".                          */
/* ************************************************************************** */
void	ft_rotate_both(t_vars *vars)
{
	ft_rotate_worker(&vars->stk_a);
	ft_rotate_worker(&vars->stk_b);
	ft_lstadd_back(&vars->cmds, ft_lstnew(ft_strdup("rr\n")));
}
