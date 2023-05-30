/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:03:21 by melee             #+#    #+#             */
/*   Updated: 2023/05/29 12:57:30 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int together)
{
	t_list	*temp;

	if (*stack_b)
	{
		ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->content));
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
	}
	if (!together)
		ft_putstr_fd("pa\n", FD);
}

void	pb(t_list **stack_a, t_list **stack_b, int together)
{
	t_list	*temp;

	if (*stack_a)
	{
		ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->content));
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	if (!together)
		ft_putstr_fd("pb\n", FD);
}
