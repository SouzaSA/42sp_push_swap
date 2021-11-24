/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:09:39 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 13:10:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* reverse rotate - shift down all elements of a stack by 1. The last element */
/* becomes the first one. Print "rra" or "rrb" message.                       */
/* ************************************************************************** */
void	ft_rev_rotate(t_stack *stack, char name, t_list **cmds)
{
	char	print_val[5];

	print_val[0] = 'r';
	print_val[1] = 'r';
	print_val[2] = name;
	print_val[3] = '\n';
	print_val[4] = '\0';
	ft_reverse_rotate_worker(stack);
	ft_lstadd_back(cmds, ft_lstnew(ft_strdup(print_val)));
}

/* ************************************************************************** */
/* rotate both - shift down all elements of both stacks by 1. The last        */
/* element becomes the first one, in both stacks. Print "rrr".                */
/* ************************************************************************** */
void	ft_rev_rotate_both(t_vars *vars)
{
	ft_reverse_rotate_worker(&vars->stk_a);
	ft_reverse_rotate_worker(&vars->stk_b);
	ft_lstadd_back(&vars->cmds, ft_lstnew(ft_strdup("rrr\n")));
}
