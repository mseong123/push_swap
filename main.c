/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:03:57 by melee             #+#    #+#             */
/*   Updated: 2023/05/18 15:53:23 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_string_error(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '-' && i == 0)
				res = 1;	
			else
				res = -1;
		}
		i++;
	}
	return (res);
}


t_list	*populate(t_list *stackA, int argc, char **argv)
{
	int		i;
	t_list	*node;

	i = 1;
	while (i < argc)
	{
		if (stackA)
			node = stackA;
		if (check_string_error(argv[i]) == -1)
			return (NULL);
		while (node)
		{
			if (ft_atoi(node->content) == ft_atoi(argv[i]))
				return (NULL);
			node = node->next;
		}
		if (ft_atoi_long(argv[i]) > 2147483647 || ft_atoi_long(argv[i]) < -2147483648)
			return (NULL);
		ft_lstadd_back(&stackA, ft_lstnew(argv[i]));
		i++;
	}
	return (stackA);
}

void ft_printf(void *content)
{
	printf("%s\n",content);
}

int	main(int argc, char **argv)
{
	t_list	*stackA;
   	t_list	*stackB;
	
	stackA = NULL;	
	stackB = NULL;
	if (argc > 1)
	{
		stackA = populate(stackA, argc, argv);
		if (!stackA)
		{
			ft_putstr_fd("Error\n",FD);
			return (0);
		}
	}
	sa(stackA);
	ft_lstiter(stackA, ft_printf);
	return (0);
}


