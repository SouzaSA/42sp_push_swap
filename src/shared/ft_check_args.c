/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:19:33 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/27 21:14:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_has_invalid_arg(int argc, char **argv);
static int	ft_has_invalid_char(char **argv);
static int	ft_check_value(char *nb);
static int	ft_has_duplicates(int *values, int size);

/* ************************************************************************** */
/* check args - check if all entries are integers and there are no duplicates */
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
	error = ft_has_invalid_arg(argc, argv);
	vals = ft_get_splited_vals(argc, argv);
	num_vals = ft_get_num_vals(vals);
	while (vals[i] && !error)
	{
		error = ft_has_invalid_char(vals[i]);
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

static int	ft_has_invalid_arg(int argc, char **argv)
{
	int	i;
	int	j;
	int	has_invalid;
	int	arg_len;

	i = 1;
	has_invalid = 0;
	while (i < argc)
	{
		j = 0;
		arg_len = ft_strlen(argv[i]);
		if (ft_strlen(argv[i]) == 0)
			has_invalid = 1;
		while (argv[i][j] && !ft_isdigit(argv[i][j]))
			j++;
		if (j == arg_len)
			has_invalid = 1;
		i++;
	}
	return (has_invalid);
}

static int	ft_has_invalid_char(char **vals)
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
			if (!ft_isdigit(vals[i][j]) && vals[i][j] != '+' \
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
	int		i;
	int		error;
	long	number;

	i = 0;
	error = 0;
	while (nb[i])
	{
		if ((nb[i] == '+' || nb[i] == '-') && !ft_isdigit(nb[i + 1]))
			error = 1;
		i++;
	}
	if (!error)
	{
		number = ft_atoi(nb);
		if ((number < 0 && nb[0] != '-') || (number > 0 && nb[0] == '-'))
			error = 1;
	}
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
