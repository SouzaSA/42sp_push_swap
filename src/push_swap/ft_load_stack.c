/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:20:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/19 13:15:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_load_stack_a(int num_vals, char ***vals, t_stack *stack_a);
static void	ft_change_values(int *values, int *aux_vector, int size);

/* ************************************************************************** */
/* load - load the stacks and alloc memory to values arrays a and b set stack */
/* size and set top index value, -1 is for empty stack. Change vector values  */
/* to a consecutive values. ex. {10, 3, 15, 44, 1, 999} => {2, 1, 3, 4, 0, 5} */
/* ************************************************************************** */
void	ft_load(int argc, char **argv, t_vars *vars)
{
	int		num_vals;
	char	***vals;

	vals = ft_get_splited_vals(argc, argv);
	num_vals = ft_get_num_vals(vals);
	vars->stk_b.size = num_vals;
	vars->stk_b.top = -1;
	vars->stk_b.values = malloc(vars->stk_b.size * sizeof(int));
	vars->stk_a.size = num_vals;
	vars->stk_a.top = num_vals - 1;
	vars->stk_a.values = NULL;
	ft_load_stack_a(num_vals, vals, &vars->stk_a);
	ft_destroy_splited_vals(vals);
}

static void	ft_load_stack_a(int num_vals, char ***vals, t_stack *stack_a)
{
	int	*aux_vector;

	stack_a->values = ft_load_values(vals, num_vals);
	aux_vector = ft_load_values(vals, num_vals);
	ft_merge_sort(aux_vector, 0, num_vals - 1);
	ft_change_values(stack_a->values, aux_vector, num_vals);
	free(aux_vector);
}

int	*ft_load_values(char ***vals, int num_vals)
{
	int	i;
	int j;
	int k;
	int *values;

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

static void	ft_change_values(int *values, int *aux_vector, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (aux_vector[j] == values[i])
				values[i] = j;
			j++;
		}
		i++;
	}
}

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
