/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:20:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:13:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* destroy stacks - free alloced memory on stacks values, and set top and     */
/* size to right values.                                                      */
/* ************************************************************************** */
void	ft_destroy_stacks(t_vars *vars)
{
	vars->stk_a.top = -1;
	vars->stk_a.size = 0;
	free(vars->stk_a.values);
	vars->stk_b.top = -1;
	vars->stk_b.size = 0;
	free(vars->stk_b.values);
}
