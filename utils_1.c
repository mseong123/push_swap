/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:23:49 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 11:20:37 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *stack_a)
{
	int		prev;
	t_list	*node;

	prev = ft_atoi(stack_a->content);
	node = stack_a;
	while (node)
	{
		node = node->next;
		if (node && ft_atoi(node->content) < prev)
			return (0);
		if (node)
			prev = ft_atoi(node->content);
	}
	return (1);
}

void	del_content(void *content)
{
	free(content);
}

void	del_content1(void *content)
{
	content = NULL;
}

void	ft_printf(void *content)
{
	char	*str;

	str = (char *)content;
	ft_putstr_fd(content, FD);
	ft_putchar_fd('\n', FD);
}

void	free_stack(t_list *stack, int argc)
{
	if (argc == 2)
		ft_lstclear(&stack, del_content);
	else
		ft_lstclear(&stack, del_content1);
}
