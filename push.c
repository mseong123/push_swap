/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:03:21 by melee             #+#    #+#             */
/*   Updated: 2023/05/19 11:15:02 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stackA, t_list **stackB)
{
	t_list *temp;
	if (*stackB)
	{
		ft_lstadd_front(stackA, ft_lstnew((*stackB)->content));
		temp = *stackB;
		*stackB = (*stackB)->next;
		free(temp);
	}
	ft_putstr_fd("pa\n", FD);
}

void	pb(t_list **stackA, t_list **stackB)
{
	t_list *temp;
	if (*stackA)
	{
		ft_lstadd_front(stackB, ft_lstnew((*stackA)->content));
		temp = *stackA;
		*stackA = (*stackA)->next;
		free(temp);
	}
	ft_putstr_fd("pb\n", FD);
}
