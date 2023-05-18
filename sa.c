/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:53:59 by melee             #+#    #+#             */
/*   Updated: 2023/05/18 12:40:14 by melee            ###   ########.fr       */
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
}
