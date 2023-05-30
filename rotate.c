/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:25:03 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 13:18:28 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int together)
{
	t_list	*temp;
	t_list	*last;

	temp = NULL;
	last = NULL;
	if (*stack_a && (*stack_a)->next)
	{
		last = ft_lstlast(*stack_a);
		last->next = *stack_a;
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
	}
	if (!together)
		ft_putstr_fd("ra\n", FD);
}

void	rb(t_list **stack_b, int together)
{
	t_list	*temp;
	t_list	*last;

	temp = NULL;
	last = NULL;
	if (*stack_b && (*stack_b)->next)
	{
		last = ft_lstlast(*stack_b);
		last->next = *stack_b;
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
	}
	if (!together)
		ft_putstr_fd("rb\n", FD);
}

void	rr(t_list **stack_a, t_list **stack_b, int together)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (!together)
		ft_putstr_fd("rr\n", FD);
}
