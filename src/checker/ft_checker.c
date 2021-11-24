/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:32:19 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 13:26:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include <stdio.h>//tirar

static int	ft_cmd_checker(char *cmd);
static int	ft_check_cmd_end(char *cmd, int nxt_idx);

int	ft_checker(t_vars *vars)
{
	char *cmd;
	cmd = get_next_line(0);
	while (cmd[0] != '\n')
	{
		if (ft_cmd_checker(cmd))
			printf("correcto\n");
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
	printf("%d\n", vars->stk_a.values[0]);
	return (0);
}

static int	ft_cmd_checker(char *cmd)
{
	int	valid;
	int cmd_len;

	valid = 0;
	cmd_len = ft_strlen(cmd);
	if (cmd[0] == 's' && cmd_len == 3)
		valid = ft_check_cmd_end(cmd, 1);
	if (cmd[0] == 'p' && cmd_len == 3)
		valid = ft_check_cmd_end(cmd, 1);
	if (cmd[0] == 'r' && cmd_len == 3)
		valid = ft_check_cmd_end(cmd, 1);
	if (cmd[0] == 'r' && cmd_len == 4)
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
