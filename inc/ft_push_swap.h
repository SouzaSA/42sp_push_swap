/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:00:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/21 22:37:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	int	top;
	int	size;
	int	*values;
}	t_stack;

typedef struct s_vars
{
	t_stack	stk_a;
	t_stack	stk_b;
	t_list	*cmds;
}	t_vars;

int		ft_check_args(int argc, char **argv);
int		ft_is_ordered_stk_a(t_stack *stk_a);
void	ft_destroy_stacks(t_vars *vars);
void	ft_push(t_vars *vars, char name);
void	ft_rev_rotate(t_stack *stack, char name, t_list **cmds);
void	ft_rev_rotate_both(t_vars *vars);
void	ft_rotate(t_stack *stack, char name, t_list **cmds);
void	ft_rotate_both(t_vars *vars);
void	ft_swap_one(t_stack *stack, char name, t_list **cmds);
void	ft_swap_both(t_vars *vars);
void	ft_load(int argc, char **argv, t_vars *vars);
void	ft_merge_sort(int *values, int start, int end);
int		ft_push_swap(t_vars *vars);
void	ft_order_small_mess(t_vars *vars);
void	ft_manage_a(t_vars *vars, int size);

void	ft_separate_stk_a(t_vars *vars, int blk, int flag);
void	ft_separate_stk_b(t_vars *vars, int blk, int flag);
int		ft_quick_pivot(t_stack *stk, int len, int k);
void	ft_sort_two_stack_a(t_stack *stk_a, t_list **cmds);
void	ft_sort_three_stack_a(t_stack *stk_a, int len, t_list **cmds);
void	ft_sort_two_stack_b(t_vars *vars);
void	ft_sort_three_stack_b(t_vars *vars, int len);

int		ft_check_reverse_ordered(t_vars *vars);
void	ft_sort_stack_a(t_vars *vars, int len);
void	ft_sort_three(t_stack *stk_a, int len, t_list **cmds);
void	ft_sort_four(t_vars *vars, int len);

void	ft_write_move(void *str);
char	***ft_get_splited_vals(int argc, char **argv);
int		ft_get_num_vals(char ***splited_vals);
int		*ft_load_values(char ***vals, int num_vals);
void	ft_destroy_splited_vals(char ***splited_vals);
#endif
