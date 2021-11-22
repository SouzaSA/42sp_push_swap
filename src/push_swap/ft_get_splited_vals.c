/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_splited_vals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:10:34 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 21:12:24 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	***ft_get_splited_vals(int argc, char **argv)
{
	int		i;
	int		j;
	char	***vals;

	i = 1;
	j = 0;
	vals = (char ***)malloc(argc * sizeof(char **));
	while (i < argc)
	{
		vals[j] = ft_split(argv[i], ' ');
		i++;
		j++;
	}
	vals[j] = NULL;
	return (vals);
}
