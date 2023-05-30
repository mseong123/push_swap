/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:53:59 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 13:18:52 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a, int together)
{
	void	*temp;

	if (stack_a && stack_a->next)
	{
		temp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = temp;
	}
	if (!together)
		ft_putstr_fd("sa\n", FD);
}

void	sb(t_list *stack_b, int together)
{
	void	*temp;

	if (stack_b && stack_b->next)
	{
		temp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = temp;
	}
	if (!together)
		ft_putstr_fd("sb\n", FD);
}

void	ss(t_list *stack_a, t_list *stack_b, int together)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	if (!together)
		ft_putstr_fd("ss\n", FD);
}
