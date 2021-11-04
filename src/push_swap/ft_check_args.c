/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:19:33 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/04 10:21:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_has_invalid(char **argv);
static int	ft_has_duplicates(int *values, int size);
static int	*ft_get_int_array(int size, char **argv);

/* ************************************************************************** */
/* check args - that all entries are integers and that there are no duplicate */
/* values.                                                                    */
/* ************************************************************************** */
int	ft_check_args(int argc, char **argv)
{
	int		i;
	int		error;
	int		*values;
	char	**argv_split;

	i = 0;
	values = NULL;
	error = 0;
	while (i < argc)
	{
		argv_split = ft_split(argv[i], ' ');
		error = ft_has_invalid(argv_split);
		if (!error)
			values = ft_get_int_array(ft_split_len(argv_split), argv_split);
		if (values)
			error = ft_has_duplicates(values, ft_split_len(argv_split));
		else
			error = 1;
		free(values);
		ft_split_destroy(argv_split);
		i++;
	}
	return (error);
}

static int	ft_has_invalid(char **vals)
{
	int	i;
	int	j;
	int	arg_len;
	int	error;

	i = 1;
	error = 0;
	while (vals[i])
	{
		j = 0;
		arg_len = ft_strlen(vals[i]);
		while (j < arg_len)
		{
			if (!ft_isdigit(vals[i][j]))
			{
				error = 1;
			}
			j++;
		}
		i++;
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

static int	*ft_get_int_array(int size, char **vals)
{
	int	i;
	int	*values;

	i = 0;
	values = malloc(size * sizeof(int));
	if (values)
	{
		while (i < size)
		{
			values[i] = ft_atoi(vals[i]);
			if ((values[i] == 0 || values[i] == -1) && ft_strlen(vals[i]) > 2)
			{
				free(values);
				values = NULL;
				break ;
			}
			i++;
		}
	}
	return (values);
}
