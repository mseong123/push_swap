/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:25:03 by melee             #+#    #+#             */
/*   Updated: 2023/05/19 11:13:58 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stackA)
{
	t_list *temp;
	t_list *last;

	temp = NULL;
	last = NULL;
	if (*stackA && (*stackA)->next)
	{
		last = ft_lstlast(*stackA);
		last->next = *stackA;
		temp = *stackA;
		temp->prev = last;
		*stackA = (*stackA)->next;
		(*stackA)->prev = NULL;
		temp->next = NULL;
	}
	ft_putstr_fd("ra\n", FD);
}

void	rb(t_list **stackB)
{
	t_list *temp;
	t_list *last;

	temp = NULL;
	last = NULL;
	if (*stackB && (*stackB)->next)
	{
		last = ft_lstlast(*stackB);
		last->next = *stackB;
		temp = *stackB;
		temp->prev = last;
		*stackB = (*stackB)->next; 	
		(*stackB)->prev = NULL;
		temp->next = NULL;
	}
	ft_putstr_fd("rb\n", FD);
}

void	rr(t_list **stackA, t_list **stackB)
{
	t_list *temp;
	t_list *last;

	temp = NULL;
	last = NULL;
	if (*stackA && (*stackA)->next)
	{
		last = ft_lstlast(*stackA);
		last->next = *stackA;
		temp = *stackA;
		temp->prev = last;
		*stackA = (*stackA)->next; 	
		(*stackA)->prev = NULL;
		temp->next = NULL;
	}
	temp = NULL;
	last = NULL;
	if (*stackB && (*stackB)->next)
	{
		last = ft_lstlast(*stackB);
		last->next = *stackB;
		temp = *stackB;
		temp->prev = last;
		*stackB = (*stackB)->next; 	
		(*stackB)->prev = NULL;
		temp->next = NULL;
	}
	ft_putstr_fd("rr\n", FD);
}

