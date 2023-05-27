/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:16:03 by melee             #+#    #+#             */
/*   Updated: 2023/05/25 12:18:41 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stackA)
{
	t_list *temp;
	t_list *second_last;

	temp = NULL;
	second_last = *stackA;
	if (*stackA && (*stackA)->next)
	{
		while (second_last->next->next)
			second_last = second_last->next;
		temp = ft_lstlast(*stackA);
		second_last->next = NULL;
		temp->next = *stackA;
		(*stackA)->prev = temp;
		temp->prev = NULL;
		*stackA = temp;	
	}
	ft_putstr_fd("rra\n", FD);
}

void	rrb(t_list **stackB)
{
	t_list *temp;
	t_list *second_last;

	temp = NULL;
	second_last = *stackB;
	if (*stackB && (*stackB)->next)
	{
		while (second_last->next->next)
			second_last=second_last->next;
		temp = ft_lstlast(*stackB);
		second_last->next = NULL;
		temp->next = *stackB;
		(*stackB)->prev = temp;
		temp->prev = NULL;
		*stackB = temp;	
	}
	ft_putstr_fd("rrb\n", FD);
}

void	rrr(t_list **stackA, t_list **stackB)
{
	t_list *temp;
	t_list *second_last;

	temp = NULL;
	second_last = *stackA;
	if (*stackA && (*stackA)->next)
	{
		while (second_last->next->next)
			second_last = second_last->next;
		temp = ft_lstlast(*stackA);
		second_last->next = NULL;
		temp->next = *stackA;
		(*stackA)->prev = temp;
		temp->prev = NULL;
		*stackA = temp;	
	}
	temp = NULL;
	second_last = *stackB;
	if (*stackB && (*stackB)->next)
	{
		while (second_last->next->next)
			second_last=second_last->next;
		temp = ft_lstlast(*stackB);
		second_last->next = NULL;
		temp->next = *stackB;
		(*stackB)->prev = temp;
		temp->prev = NULL;
		*stackB = temp;	
	}
	ft_putstr_fd("rrr\n", FD);
}
