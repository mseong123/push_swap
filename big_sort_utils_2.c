/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:08:15 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 13:20:09 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_temp(t_operations *ptr)
{
	ptr->temp_ra = 0;
	ptr->temp_rb = 0;
	ptr->temp_rra = 0;
	ptr->temp_rrb = 0;
	ptr->temp_rr = 0;
	ptr->temp_rrr = 0;
}

void	compare_operations_sub(t_operations *ptr)
{
		ptr->ra = ptr->temp_ra;
		ptr->rb = ptr->temp_rb;
		ptr->rra = ptr->temp_rra;
		ptr->rrb = ptr->temp_rrb;
		ptr->rr = ptr->temp_rr;
		ptr->rrr = ptr->temp_rrr;
}

void	compare_operations(t_operations *ptr)
{
	int	current_total;
	int	temp_total;

	current_total = ptr->ra + ptr->rb + ptr->rra
		+ ptr->rrb + ptr->rr + ptr-> rrr;
	temp_total = ptr->temp_ra + ptr->temp_rb + ptr->temp_rra
		+ ptr->temp_rrb + ptr->temp_rr + ptr-> temp_rrr;
	if (ptr->first_time)
	{
		ptr->ra = ptr->temp_ra;
		ptr->rb = ptr->temp_rb;
		ptr->rra = ptr->temp_rra;
		ptr->rrb = ptr->temp_rrb;
		ptr->rr = ptr->temp_rr;
		ptr->rrr = ptr->temp_rrr;
		ptr->first_time = 0;
	}
	else if (temp_total < current_total)
		compare_operations_sub(ptr);
	reset_temp(ptr);
}

void	exec_ops_sub(t_list **stack_a, t_list **stack_b, t_operations *ptr)
{
	while (ptr->rra)
	{
		rra(stack_a, 0);
		ptr->rra--;
	}
	while (ptr->rrb)
	{
		rrb(stack_b, 0);
		ptr->rrb--;
	}
	while (ptr->rr)
	{
		rr(stack_a, stack_b, 0);
		ptr->rr--;
	}
	while (ptr->rrr)
	{
		rrr(stack_a, stack_b, 0);
		ptr->rrr--;
	}
}

void	exec_ops(t_list **stack_a, t_list **stack_b, t_operations *ptr)
{
	while (ptr->ra)
	{
		ra(stack_a, 0);
		ptr->ra--;
	}	
	while (ptr->rb)
	{
		rb(stack_b, 0);
		ptr->rb--;
	}
	exec_ops_sub(stack_a, stack_b, ptr);
	pb(stack_a, stack_b, 0);
	ptr->first_time = 1;
}
