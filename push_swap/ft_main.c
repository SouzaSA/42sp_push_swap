/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:32:03 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/20 18:21:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc > 1)
	{
		if (ft_check_args(argc, argv))
		{
			ft_load_stacks(argc, argv, &stack_a, &stack_b);
			ft_push_swap(&stack_a, &stack_b);
			ft_destroy_stacks(&stack_a, &stack_b);
		}
		else
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}