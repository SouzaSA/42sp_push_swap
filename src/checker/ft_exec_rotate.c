/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:44:54 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 19:42:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/* ************************************************************************** */
/* rotate - shift up all elements of a stack by 1. The first element becomes  */
/* the last one.                                                              */
/* ************************************************************************** */
void	ft_exec_rotate(t_vars *vars, char name)
{
	if (name == 'a')
		ft_rotate_worker(&vars->stk_a);
	if (name == 'b')
		ft_rotate_worker(&vars->stk_b);
}

/* ************************************************************************** */
/* rotate both - shift up all elements of both stacks by 1. The first element */
/* becomes the last one, in both stacks.                                      */
/* ************************************************************************** */
void	ft_exec_rotate_both(t_vars *vars)
{
	ft_rotate_worker(&vars->stk_a);
	ft_rotate_worker(&vars->stk_b);
}
