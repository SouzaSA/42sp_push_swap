/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:30:22 by sde-alva          #+#    #+#             */
/*   Updated: 2021/11/24 19:57:58 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include "ft_shared.h"

int		ft_checker(t_vars *vars);
int		ft_exec_cmds(t_vars *vars);
void	ft_exec_push(t_vars *vars, char name);
void	ft_exec_rev_rotate(t_vars *vars, char name);
void	ft_exec_rev_rotate_both(t_vars *vars);
void	ft_exec_rotate(t_vars *vars, char name);
void	ft_exec_rotate_both(t_vars *vars);
void	ft_swap_one(t_vars *vars, char name);
void	ft_swap_both(t_vars *vars);
#endif