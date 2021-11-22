/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_splited_vals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:10:34 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/22 09:18:44 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void ft_change_isspace_to_space(char *str);

char	***ft_get_splited_vals(int argc, char **argv)
{
	int		i;
	int		j;
	char	***vals;
	char	*aux;

	i = 1;
	j = 0;
	vals = (char ***)malloc(argc * sizeof(char **));
	while (i < argc)
	{
		aux = ft_strdup(argv[i]);
		ft_change_isspace_to_space(aux);
		vals[j] = ft_split(aux, ' ');
		free(aux);
		i++;
		j++;
	}
	vals[j] = NULL;
	return (vals);
}

static void ft_change_isspace_to_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		i++;
	}
}
