/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:05:32 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 13:15:49 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHARED_H
# define FT_SHARED_H
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

void	ft_reverse_rotate_worker(t_stack *stack);
void	ft_push_worker(t_stack *stack_x, t_stack *stack_y);
void	ft_rotate_worker(t_stack *stack);
void	ft_swap_worker(t_stack *stack);

int		ft_check_args(int argc, char **argv);
int		ft_is_sorted_stk_a(t_stack *stk_a);
void	ft_destroy_splited_vals(char ***splited_vals);
void	ft_destroy_stacks(t_vars *vars);
int		ft_get_num_vals(char ***splited_vals);
char	***ft_get_splited_vals(int argc, char **argv);
void	ft_load(int argc, char **argv, t_vars *vars);
int		*ft_load_values(char ***vals, int num_vals);
#endif
