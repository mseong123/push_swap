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

	temp = NULL;
	if (*stackA && (*stackA)->next)
	{
		ft_lstlast(*stackA)->next = *stackA;
		temp = *stackA;
		*stackA = (*stackA)->next; 	
		temp->next = NULL;
	}
	ft_putstr_fd("ra\n", FD);
}

void	rb(t_list **stackB)
{
	t_list *temp;

	temp = NULL;
	if (*stackB && (*stackB)->next)
	{
		ft_lstlast(*stackB)->next = *stackB;
		temp = *stackB;
		*stackB = (*stackB)->next; 	
		temp->next = NULL;
	}
	ft_putstr_fd("rb\n", FD);
}

void	rr(t_list **stackA, t_list **stackB)
{
	t_list *temp;

	temp = NULL;
	if (*stackA && (*stackA)->next)
	{
		ft_lstlast(*stackA)->next = *stackA;
		temp = *stackA;
		*stackA = (*stackA)->next; 	
		temp->next = NULL;
	}
	temp = NULL;
	if (*stackB && (*stackB)->next)
	{
		ft_lstlast(*stackB)->next = *stackB;
		temp = *stackB;
		*stackB = (*stackB)->next; 	
		temp->next = NULL;
	}
	ft_putstr_fd("rr\n", FD);
}

