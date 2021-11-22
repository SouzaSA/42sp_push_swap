/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:20:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 21:12:22 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/* load - load the stacks and alloc memory to values arrays a and b set stack */
/* size and set top index value, -1 is for empty stack. Change vector values  */
/* to a consecutive values. ex. {10, 3, 15, 44, 1, 999} => {2, 1, 3, 4, 0, 5} */
/* ************************************************************************** */
void	ft_load(int argc, char **argv, t_vars *vars)
{
	int		num_vals;
	char	***vals;

	vals = ft_get_splited_vals(argc, argv);
	num_vals = ft_get_num_vals(vals);
	vars->stk_b.size = num_vals;
	vars->stk_b.top = -1;
	vars->stk_b.values = malloc(vars->stk_b.size * sizeof(int));
	vars->stk_a.size = num_vals;
	vars->stk_a.top = num_vals - 1;
	vars->stk_a.values = NULL;
	vars->stk_a.values = ft_load_values(vals, num_vals);
	ft_destroy_splited_vals(vals);
}
