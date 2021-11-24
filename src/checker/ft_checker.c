/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:32:19 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/23 21:32:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

#include <stdio.h>
int	ft_checker(t_vars *vars)
{
	char *cmd;
	cmd = get_next_line(0);
	while (cmd[0] != '\n')
	{
		printf("%s\n", cmd);
		cmd = get_next_line(0);
	}
	printf("%d\n", vars->stk_a.values[0]);
	return (0);
}
