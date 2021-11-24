/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:44:58 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 16:30:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/* ************************************************************************** */
/* swap one - swap the first 2 elements at the top of a stack. Do nothing if  */
/* there is only one or no elements. Name refers to to wich stack is in use.  */
/* ************************************************************************** */
void	ft_swap_one(t_vars *vars, char name)
{
	if (name == 'a' && vars->stk_a.top > 0)
		ft_swap_worker(&vars->stk_a);
	else if (name == 'b' && vars->stk_b.top > 0)
		ft_swap_worker(&vars->stk_b);
}

/* ************************************************************************** */
/* swap both - swap the first 2 elements at the top of both stacks at same    */
/* time.                                                                      */
/* ************************************************************************** */
void	ft_swap_both(t_vars *vars)
{
	if (vars->stk_a.top > 0 && vars->stk_b.top > 0)
	{
		ft_swap_worker(&vars->stk_a);
		ft_swap_worker(&vars->stk_b);
	}
}
