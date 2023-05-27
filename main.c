/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:03:57 by melee             #+#    #+#             */
/*   Updated: 2023/05/27 11:33:06 by melee            ###   ########.fr       */
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
	node = NULL;
	while (i < argc)
	{	
		if (!node)
			node = stackA;		
		if (check_string_error(argv[i]) == -1)
			return (NULL);	
		while (node)
		{
			if (ft_atoi_long(node->content) == ft_atoi_long(argv[i]))
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

int	sorted(t_list *stackA)
{
	int	prev;
	
	prev = ft_atoi(stackA->content);
	while (stackA)
	{
		stackA = stackA->next;
		if (stackA && ft_atoi(stackA->content) < prev)
		{
			return (0);
		}
		if (stackA)
			prev = ft_atoi(stackA->content);
	}
	return (1);
}

void	ft_lstiterbackwards(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (lst && f)
	{
		node = lst;
		while (node)
		{
			f(node->content);
			node = node->prev;
		}
	}
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
	if (sorted(stackA))
		printf("sorted\n");
	sort(&stackA, &stackB);
	
	/*testing
	pb(&stackA,&stackB);

	pb(&stackA,&stackB);
	pb(&stackA,&stackB);
	pb(&stackA,&stackB);
	rrr(&stackA,&stackB);
	ra(&stackA);
	pa(&stackA,&stackB);
	rr(&stackA,&stackB);
	rb(&stackB);
	pb(&stackA,&stackB);

	printf("stackA\n");	
	ft_lstiter(stackA, ft_printf);
	stackA=ft_lstlast(stackA);
printf("stackA backwards\n");	
	ft_lstiterbackwards(stackA, ft_printf);

printf("stackB\n");	
	ft_lstiter(stackB, ft_printf);
	stackB=ft_lstlast(stackB);
printf("stackB backwards\n");	
	ft_lstiterbackwards(stackB, ft_printf);

	*/
	return (0);
}


