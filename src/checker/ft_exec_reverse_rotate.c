/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:44:51 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 15:54:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/* ************************************************************************** */
/* reverse rotate - shift down all elements of a stack by 1. The last element */
/* becomes the first one                                                      */
/* ************************************************************************** */
void	ft_exec_rev_rotate(t_vars *vars, char name)
{
	if (name == 'a')
		ft_reverse_rotate_worker(&vars->stk_a);
	if (name == 'b')
		ft_reverse_rotate_worker(&vars->stk_b);
}

/* ************************************************************************** */
/* rotate both - shift down all elements of both stacks by 1. The last        */
/* element becomes the first one, in both stacks. Print "rrr".                */
/* ************************************************************************** */
void	ft_exec_rev_rotate_both(t_vars *vars)
{
	ft_reverse_rotate_worker(&vars->stk_a);
	ft_reverse_rotate_worker(&vars->stk_b);
}
