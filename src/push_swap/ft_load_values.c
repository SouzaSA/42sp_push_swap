/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:04:10 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/21 17:41:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*ft_load_values(char ***vals, int num_vals)
{
	int	i;
	int	j;
	int	k;
	int	*values;

	i = 0;
	k = num_vals - 1;
	values = (int *)malloc(num_vals * sizeof(int));
	while (vals[i])
	{
		j = 0;
		while (vals[i][j])
		{
			values[k] = ft_atoi(vals[i][j]);
			j++;
			k--;
		}
		i++;
	}
	return (values);
}
