/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:00:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/18 19:39:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "libft.h"
#include <stdio.h>//tirar

# define MAX_I 2147483647 //tirar
# define MIN_I -2147483648 //tirar

typedef struct s_stack
{
	int	top;
	int size;
	int	*values;
}	t_stack;

int		ft_check_args(int argc, char **argv);
int		ft_is_ordered_stk_a(t_stack *stk_a);
void	ft_destroy_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_push(t_stack *stack_a, t_stack *stack_b, char name);
void	ft_reverse_rotate(t_stack *stack, char name);
void	ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate(t_stack *stack, char name);
void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	ft_swap_one(t_stack *stack, char name);
void	ft_swap_both(t_stack *stack_a, t_stack *stack_b);
void	ft_load(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void	ft_merge_sort(int *values, int start, int end);
int		ft_push_swap(t_stack *stk_a, t_stack *stk_b);
void	ft_order_small_mess(t_stack *stk_a, t_stack *stk_b);
void	ft_manage_a(t_stack *stk_a, t_stack *stk_b, int size);

void	ft_separate_stk_a(t_stack *stk_a, t_stack *stk_b, int blk, int flag);
void	ft_separate_stk_b(t_stack *stk_a, t_stack *stk_b, int blk_a, int *cnt_b);
int		ft_quick_pivot(t_stack *stk, int len, int k);
void	ft_sort_two_stack_a(t_stack *stk_a);
void	ft_sort_three_stack_a(t_stack *stk_a, int len);
void	ft_sort_two_stack_b(t_stack *stk_a, t_stack *stk_b);
void	ft_sort_three_stack_b(t_stack *stk_a, t_stack *stk_b, int len);

int		check_rev(t_stack *stk_a, t_stack *stk_b);
void	ft_sort_stack_a(t_stack *stk_a, t_stack *stk_b, int len);
void	ft_sort_three(t_stack *stk_a, int len);


int		*ft_load_values(char ***vals, int num_vals);
void	ft_destroy_splited_vals(char ***splited_vals);
char	***ft_get_splited_vals(int argc, char **argv);
int		ft_get_num_vals(char ***splited_vals);
#endif
