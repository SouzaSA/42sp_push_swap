/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:32:19 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/27 12:55:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int	ft_cmd_checker(char *cmd);
static int	ft_check_cmd_end(char *cmd, int nxt_idx);
static void	ft_exit_error(t_vars *vars, char *cmd);

int	ft_checker(t_vars *vars)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd && cmd[0] != '\n')
	{
		if (ft_cmd_checker(cmd))
			ft_lstadd_back(&vars->cmds, ft_lstnew(ft_strdup(cmd)));
		else
			ft_exit_error(vars, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
	if (ft_exec_cmds(vars))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

static int	ft_cmd_checker(char *cmd)
{
	int	valid;
	int	cmd_len;

	valid = 0;
	cmd_len = ft_strlen(cmd);
	if (cmd[0] == 's' && cmd_len == 3)
		valid = ft_check_cmd_end(cmd, 1);
	if (cmd[0] == 'p' && cmd_len == 3)
		valid = ft_check_cmd_end(cmd, 1);
	if (cmd[0] == 'r' && cmd_len == 3)
		valid = ft_check_cmd_end(cmd, 1);
	if (cmd[0] == 'r' && cmd[1] == 'r' && cmd_len == 4)
		valid = ft_check_cmd_end(cmd, 2);
	return (valid);
}

static int	ft_check_cmd_end(char *cmd, int nxt_idx)
{
	int	valid;

	valid = 0;
	if (cmd[0] == 'p')
	{
		if ((cmd[1] == 'a' || cmd[1] == 'b') && cmd[2] == '\n')
			valid = 1;
	}
	else
	{
		if ((cmd[nxt_idx] == 'a' || cmd[nxt_idx] == 'b' \
			|| cmd[nxt_idx] == cmd[0]) && cmd[nxt_idx + 1] == '\n')
			valid = 1;
	}
	return (valid);
}

static void	ft_exit_error(t_vars *vars, char *cmd)
{
	if (vars->cmds)
		ft_lstclear(&vars->cmds, &free);
	free(cmd);
	ft_destroy_stacks(vars);
	write(2, "Error\n", 6);
	exit(1);
}
