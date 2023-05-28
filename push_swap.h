/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:58:16 by melee             #+#    #+#             */
/*   Updated: 2023/05/28 13:36:15 by melee            ###   ########.fr       */
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

void		sa(t_list *stackA);
void		sb(t_list *stackB);
void		ss(t_list *stackA, t_list *stackB);
void		pa(t_list **stackA, t_list **stackB);
void		pb(t_list **stackA, t_list **stackB);
void		ra(t_list **stackA);
void		rb(t_list **stackB);
void		rr(t_list **stackA, t_list **stackB);
void		rra(t_list **stackA);
void		rrb(t_list **stackB);
void		rrr(t_list **stackA, t_list **stackB);
void		sort(t_list **stackA, t_list **stackB);
long int	ft_atoi_long(const char *str);

#endif
