/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:16:03 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 13:18:01 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int together)
{
	t_list	*temp;
	t_list	*second_last;

	temp = NULL;
	second_last = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		while (second_last->next->next)
			second_last = second_last->next;
		temp = ft_lstlast(*stack_a);
		second_last->next = NULL;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	if (!together)
		ft_putstr_fd("rra\n", FD);
}

void	rrb(t_list **stack_b, int together)
{
	t_list	*temp;
	t_list	*second_last;

	temp = NULL;
	second_last = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		while (second_last->next->next)
			second_last = second_last->next;
		temp = ft_lstlast(*stack_b);
		second_last->next = NULL;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	if (!together)
		ft_putstr_fd("rrb\n", FD);
}

void	rrr(t_list **stack_a, t_list **stack_b, int together)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (!together)
		ft_putstr_fd("rrr\n", FD);
}
