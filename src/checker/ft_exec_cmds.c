/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:46:49 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 19:56:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	ft_exec_cmd(t_vars *vars, char *cmd);

int	ft_exec_cmds(t_vars *vars)
{
	int		is_sorted;
	t_list	*instructions;

	is_sorted = 0;
	if (vars->cmds)
	{
		instructions = vars->cmds;
		while (instructions)
		{
			ft_exec_cmd(vars, instructions->content);
			instructions = instructions->next;
		}
		ft_lstclear(&vars->cmds, &free);
	}
	if (ft_is_sorted_stk_a(&vars->stk_a))
		is_sorted = 1;
	return (is_sorted);
}

static void	ft_exec_cmd(t_vars *vars, char *cmd)
{
	if (ft_strcmp("sa\n", cmd) == 0)
		ft_swap_one(vars, 'a');
	else if (ft_strcmp("sb\n", cmd) == 0)
		ft_swap_one(vars, 'b');
	else if (ft_strcmp("ss\n", cmd) == 0)
		ft_swap_both(vars);
	else if (ft_strcmp("pa\n", cmd) == 0)
		ft_exec_push(vars, 'a');
	else if (ft_strcmp("pb\n", cmd) == 0)
		ft_exec_push(vars, 'b');
	else if (ft_strcmp("ra\n", cmd) == 0)
		ft_exec_rotate(vars, 'a');
	else if (ft_strcmp("rb\n", cmd) == 0)
		ft_exec_rotate(vars, 'b');
	else if (ft_strcmp("rr\n", cmd) == 0)
		ft_exec_rotate_both(vars);
	else if (ft_strcmp("rra\n", cmd) == 0)
		ft_exec_rev_rotate(vars, 'a');
	else if (ft_strcmp("rrb\n", cmd) == 0)
		ft_exec_rev_rotate(vars, 'b');
	else if (ft_strcmp("rrr\n", cmd) == 0)
		ft_exec_rev_rotate_both(vars);
}
