/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:53:59 by melee             #+#    #+#             */
/*   Updated: 2023/05/19 11:15:26 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stackA)
{
	void	*temp;

	if (stackA->next)
	{
		temp = stackA->content;
		stackA->content = stackA->next->content;
		stackA->next->content = temp;
	}
	ft_putstr_fd("sa\n", FD);
}

void	sb(t_list *stackB)
{
	void	*temp;

	if (stackB->next)
	{
		temp = stackB->content;
		stackB->content = stackB->next->content;
		stackB->next->content = temp;
	}
	ft_putstr_fd("sb\n", FD);
}

void	ss(t_list *stackA, t_list *stackB)
{
	sa(stackA);
	sb(stackB);
}
