/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:16:03 by melee             #+#    #+#             */
/*   Updated: 2023/05/19 11:40:51 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stackA)
{
	t_list *temp;

	temp = NULL;
	if (*stackA)
	{
		temp = ft_lstlast(*stackA);
		(*stackA)->next->next = NULL;
		temp->next = *stackA;
		*stackA = temp;	
	}
	ft_putstr_fd("rra\n", FD);
}

void	rrb(t_list **stackB)
{
	t_list *temp;

	temp = NULL;
	if (*stackB)
	{
		temp = ft_lstlast(*stackB);
		(*stackB)->next->next = NULL;
		temp->next = *stackB;
		*stackB = temp;	
	}
	ft_putstr_fd("rrb\n", FD);
}

void	rrr(t_list **stackA, t_list **stackB)
{
	rra(stackA);
	rrb(stackB);
}
