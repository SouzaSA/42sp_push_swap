/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:05:49 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 12:02:38 by sde-alva         ###   ########.fr       */
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
void	ft_swap_one(t_stack *stack, char name, t_list **cmds)
{
	char	print_val[3];

	if (stack->top > 0)
	{
		print_val[0] = 's';
		print_val[1] = name;
		print_val[2] = '\n';
		ft_swap(stack);
		ft_lstadd_back(cmds, ft_lstnew(ft_strdup(print_val)));
	}
}

/* ************************************************************************** */
/* swap both - swap the first 2 elements at the top of both stacks at same    */
/* time.                                                                      */
/* ************************************************************************** */
void	ft_swap_both(t_vars *vars)
{
	if (vars->stk_a.top > 0 && vars->stk_b.top > 0)
	{
		ft_swap(&vars->stk_a);
		ft_swap(&vars->stk_b);
		ft_lstadd_back(&vars->cmds, ft_lstnew(ft_strdup("ss\n")));
	}
}
