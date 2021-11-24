/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_splited_vals.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:05:45 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 21:08:25 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_destroy_splited_vals(char ***splited_vals)
{
	int	i;

	i = 0;
	while (splited_vals[i])
	{
		ft_split_destroy(splited_vals[i]);
		i++;
	}
	free(splited_vals);
}
