/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_num_vals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:08:30 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 21:09:29 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_num_vals(char ***splited_vals)
{
	int	i;
	int	num_vals;

	i = 0;
	num_vals = 0;
	while (splited_vals[i])
	{
		num_vals += ft_split_len(splited_vals[i]);
		i++;
	}
	return (num_vals);
}
