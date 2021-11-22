/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:19:33 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/21 17:49:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_has_invalid(char **argv);
static int	ft_check_value(char *nb);
static int	ft_has_duplicates(int *values, int size);

/* ************************************************************************** */
/* check args - that all entries are integers and that there are no duplicate */
/* values.                                                                    */
/* ************************************************************************** */
int	ft_check_args(int argc, char **argv)
{
	int		i;
	int		error;
	int		*values;
	int		num_vals;
	char	***vals;

	i = 0;
	values = NULL;
	error = 0;
	vals = ft_get_splited_vals(argc, argv);
	num_vals = ft_get_num_vals(vals);
	while (vals[i] && !error)
	{
		error = ft_has_invalid(vals[i]);
		i++;
	}
	if (!error)
		values = ft_load_values(vals, num_vals);
	if (values)
		error = ft_has_duplicates(values, num_vals);
	else
		error = 1;
	free(values);
	ft_destroy_splited_vals(vals);
	return (error);
}

static int	ft_has_invalid(char **vals)
{
	int		i;
	int		j;
	int		arg_len;
	int		error;

	i = 0;
	error = 0;
	while (vals[i])
	{
		j = 0;
		arg_len = ft_strlen(vals[i]);
		while (j < arg_len)
		{
			if (!ft_isdigit(vals[i][j]) && vals[i][j] != '+'
				&& vals[i][j] != '-')
			{
				error = 1;
			}
			j++;
		}
		if (!error)
			error = ft_check_value(vals[i]);
		i++;
	}
	return (error);
}

static int	ft_check_value(char *nb)
{
	int		error;
	long	number;

	error = 0;
	number = ft_atoi(nb);
	if ((number < 0 && nb[0] != '-') || (number > 0 && nb[0] == '-'))
		error = 1;
	return (error);
}

static int	ft_has_duplicates(int *values, int size)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				error = 1;
			j++;
		}
		i++;
	}
	return (error);
}
