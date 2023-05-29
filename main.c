/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:03:57 by melee             #+#    #+#             */
/*   Updated: 2023/05/29 19:09:50 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	chk_str_err(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '-' && i == 0 && ft_isdigit(str[i + 1]))
				res = 1;
			else if (str[i] == '+' && i == 0 && ft_isdigit(str[i + 1]))
				res = 1;
			else
				res = 0;
		}
		i++;
	}
	return (res);
}

int	chk_dup_str(char *str, t_list *stack_a)
{
	int	count;

	count = 0;
	while (stack_a)
	{
		if (ft_atoi_long(str) == ft_atoi_long(stack_a->content))
			count++;
		stack_a = stack_a->next;
	}
	if (count > 1)
		return (0);
	else
		return (1);
}

t_list	*split_and_populate(t_list *stack_a, char **argv)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split(argv[1], ' ');
	while (str[i])
		ft_lstadd_back(&stack_a, ft_lstnew(str[i++]));
	i = 0;
	free(str);
	return (stack_a);
}

t_list	*populate(t_list *stack_a, int argc, char **argv)
{
	int		i;
	t_list	*node;

	i = 1;
	if (argc == 2)
		stack_a = split_and_populate(stack_a, argv);
	else
		while (i < argc)
			ft_lstadd_back(&stack_a, ft_lstnew(argv[i++]));
	node = stack_a;
	while (node)
	{
		if (!chk_str_err(node->content) || !chk_dup_str(node->content, stack_a)
			|| ft_atoi_long(node->content) > 2147483647
			|| ft_atoi_long(node->content) < -2147483648)
		{
			ft_lstclear(&stack_a, del_content);
			return (NULL);
		}
		node = node->next;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = populate(stack_a, argc, argv);
		if (!stack_a || sorted(stack_a))
		{
			if (!stack_a)
				ft_putstr_fd("Error\n", FD);
			return (0);
		}	
		if (ft_lstsize(stack_a) <= 5)
			small_sort(&stack_a, &stack_b);
		else
			big_sort(&stack_a, &stack_b);
		ft_lstiter(stack_a, ft_printf);
		ft_lstclear(&stack_a, del_content);
	}
	return (0);
}
