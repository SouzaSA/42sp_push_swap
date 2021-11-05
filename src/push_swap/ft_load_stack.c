/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:20:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/04 22:52:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_load_stack_a(int num_vals, char ***vals, t_stack *stack_a);
static void	ft_load_values(int *values, char ***vals, int num_vals);
static void	ft_change_values(int *values, int *aux_vector, int size);

/* ************************************************************************** */
/* load - load the stacks and alloc memory to values arrays a and b set stack */
/* size and set top index value, -1 is for empty stack. Change vector values  */
/* to a consecutive values. ex. {10, 3, 15, 44, 1, 999} => {2, 1, 3, 4, 0, 5} */
/* ************************************************************************** */
void	ft_load(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		num_vals;
	char	***vals;

	i = 1;
	j = 0;
	num_vals = 0;
	vals = (char ***)malloc(argc * sizeof(char **));
	while (i < argc)
	{
		vals[j] = ft_split(argv[i], ' ');
		num_vals += ft_split_len(vals[j]);
		i++;
		j++;
	}
	vals[j] = NULL;
	stack_b->size = num_vals;
	stack_b->top = -1;
	stack_b->values = malloc(stack_b->size * sizeof(t_stack));
	stack_a->size = num_vals;
	stack_a->top = num_vals - 1;
	stack_a->values = malloc(stack_a->size * sizeof(t_stack));
	ft_load_stack_a(num_vals, vals, stack_a);
	i = 0;
	while (vals[i])
	{
		ft_split_destroy(vals[i]);
		i++;
	}
	free(vals);
}

static void	ft_load_stack_a(int num_vals, char ***vals, t_stack *stack_a)
{
	int	*aux_vector;

	aux_vector = (int *)malloc(num_vals * sizeof(int));
	ft_load_values(stack_a->values, vals, num_vals);
	ft_load_values(aux_vector, vals, num_vals);
	ft_merge_sort(aux_vector, 0, num_vals - 1);
	ft_change_values(stack_a->values, aux_vector, num_vals);
	free(aux_vector);
}

static void	ft_load_values(int *values, char ***vals, int num_vals)
{
	int	i;
	int j;
	int k;

	i = 0;
	k = num_vals - 1;
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
