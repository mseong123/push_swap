/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:58:16 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 13:19:24 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define FD 1

# include "libft.h"

typedef struct s_operations
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	temp_ra;
	int	temp_rb;
	int	temp_rra;
	int	temp_rrb;
	int	temp_rr;
	int	temp_rrr;
	int	first_time;
}	t_operations;

void			sa(t_list *stack_a, int together);
void			sb(t_list *stack_b, int together);
void			ss(t_list *stack_a, t_list *stack_b, int together);
void			pa(t_list **stack_a, t_list **stack_b, int together);
void			pb(t_list **stack_a, t_list **stack_b, int together);
void			ra(t_list **stack_a, int together);
void			rb(t_list **stack_b, int together);
void			rr(t_list **stack_a, t_list **stack_b, int together);
void			rra(t_list **stack_a, int together);
void			rrb(t_list **stack_b, int together);
void			rrr(t_list **stack_a, t_list **stack_b, int together);
void			big_sort(t_list **stack_a, t_list **stack_b);
long int		ft_atoi_long(const char *str);
int				sorted(t_list *stack_a);
int				find_max(t_list *stack_b);
int				find_min(t_list *stack_b);
int				find_max_or_min(int value, t_list *stack_b);
int				count_pos(int value, t_list *stack);
int				find_prev(int value, t_list *stack_b);
t_operations	*init(void);
void			reset_temp(t_operations *ptr);
void			compare_operations(t_operations *ptr);
void			exec_ops(t_list **stack_a, t_list **stack_b, t_operations *ptr);
void			upper_half(int pos[2], t_operations *ptr);
void			bottom_half(int pos[2], t_operations *ptr);
void			mix1(int pos[2], t_operations *ptr);
void			mix2(int pos[2], t_operations *ptr);
void			small_sort(t_list **stack_a, t_list **stack_b);
int				chk_str_err(char *str);
int				chk_dup_str(char *str, t_list *stack_a);
t_list			*split_and_populate(t_list *stack_a, char **argv);
t_list			*populate(t_list *stack_a, int argc, char **argv);
void			del_content(void *content);
void			del_content1(void *content);
void			ft_printf(void *content);
void			free_stack(t_list *stack, int argc);

#endif
