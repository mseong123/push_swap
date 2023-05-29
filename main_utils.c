/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:23:49 by melee             #+#    #+#             */
/*   Updated: 2023/05/29 19:10:49 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *stack_a)
{
	int	prev;

	prev = ft_atoi(stack_a->content);
	while (stack_a)
	{
		stack_a = stack_a->next;
		if (stack_a && ft_atoi(stack_a->content) < prev)
			return (0);
		if (stack_a)
			prev = ft_atoi(stack_a->content);
	}
	return (1);
}

void	del_content(void *content)
{
	free(content);
}

void	ft_printf(void *content)
{
	char	*str;

	str = (char *)content;
	ft_putstr_fd(content, FD);
	ft_putchar_fd('\n', FD);
}
