/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:32:23 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/23 21:11:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.cmds = NULL;
	if (argc > 1)
	{
		if (!ft_check_args(argc, argv))
		{
			ft_load(argc, argv, &vars);
			ft_checker(&vars);
			ft_destroy_stacks(&vars);
		}
		else
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}
