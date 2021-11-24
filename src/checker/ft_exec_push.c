/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:44:47 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 16:58:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

/* ************************************************************************** */
/* push - take the first element at the top of one stack and put it at the    */
/* top of another stack. Do nothing if the first stack is empty.              */
/* ************************************************************************** */
void	ft_exec_push(t_vars *vars, char name)
{
	if (name == 'a')
		ft_push_worker(&vars->stk_a, &vars->stk_b);
	if (name == 'b')
		ft_push_worker(&vars->stk_b, &vars->stk_a);
}
