/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:03 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 20:01:49 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.cmds = NULL;
	if (argc > 1)
	{
		if (!ft_check_args(argc, argv))
		{
			ft_load(argc, argv, &vars);
			ft_push_swap(&vars);
			ft_destroy_stacks(&vars);
		}
		else
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	if (vars.cmds)
	{
		ft_lstiter(vars.cmds, &ft_write_move);
		ft_lstclear(&vars.cmds, &free);
	}
	return (0);
}
