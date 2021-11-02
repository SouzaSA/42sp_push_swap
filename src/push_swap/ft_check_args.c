/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:19:33 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/02 20:23:47 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_has_invalid(int argc, char **argv);
static int	ft_has_duplicates(int *values, int size);
static int	*ft_get_int_array(int argc, char **argv);

/* ************************************************************************** */
/* check args - that all entries are integers and that there are no duplicate */
/* values.                                                                    */
/* ************************************************************************** */
int	ft_check_args(int argc, char **argv)
{
	int	error;
	int	*values;

	values = NULL;
	error = ft_has_invalid(argc, argv);
	if (!error)
		values = ft_get_int_array(argc, argv);
	if (values)
		error = ft_has_duplicates(values, argc - 1);
	else
		error = 1;
	free(values);
	return (error);
}

static int	ft_has_invalid(int argc, char **argv)
{
	int	i;
	int	j;
	int	arg_len;
	int	error;

	i = 1;
	error = 0;
	while (i < argc)
	{
		j = 0;
		arg_len = ft_strlen(argv[i]);
		while (j < arg_len)
		{
			if (!ft_isdigit(argv[i][j]))
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

static int	*ft_get_int_array(int argc, char **argv)
{
	int	i;
	int	*values;

	i = 0;
	values = malloc((argc - 1) * sizeof(int));
	if (values)
	{
		while (i < argc - 1)
		{
			values[i] = ft_atoi(argv[i + 1]);
			if ((values[i] == 0 || values[i] == -1) && ft_strlen(argv[i + 1]) > 2)
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
