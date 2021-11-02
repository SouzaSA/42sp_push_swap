/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:20:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/02 19:45:33 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_load_stack_a(int argc, char **argv, t_stack *stack_a);
static void	ft_load_values(int *values, int argc, char **argv);
static void	ft_change_values(int *values, int *aux_vector, int size);

/* ************************************************************************** */
/* load - load the stacks and alloc memory to values arrays a and b set stack */
/* size and set top index value, -1 is for empty stack. Change vector values  */
/* to a consecutive values. ex. {10, 3, 15, 44, 1, 999} => {2, 1, 3, 4, 0, 5} */
/* ************************************************************************** */
void	ft_load(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	stack_b->size = argc - 1;
	stack_b->top = -1;
	stack_b->values = malloc(stack_b->size * sizeof(t_stack));
	stack_a->values = malloc(stack_a->size * sizeof(t_stack));
	stack_a->size = argc - 1;
	ft_load_stack_a(argc, argv, stack_a);
}

static void	ft_load_stack_a(int argc, char **argv, t_stack *stack_a)
{
	int	*aux_vector;

	aux_vector = (int *)malloc((argc - 1) * sizeof(int));
	ft_load_values(stack_a->values, argc, argv);
	ft_load_values(aux_vector, argc, argv);
	ft_merge_sort(aux_vector, 0, argc - 2);
	ft_change_values(stack_a->values, aux_vector, argc - 1);
	free(aux_vector);
}

static void	ft_load_values(int *values, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		values[i] = ft_atoi(argv[argc - i - 1]);
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
			if (aux_vector[i] == values[j])
				values[j] = i;
			j++;
		}
		i++;
	}
}
