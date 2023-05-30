/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:03:57 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 11:53:25 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = populate(stack_a, argc, argv);
		if (!stack_a)
		{
			ft_putstr_fd("Error\n", FD);
			return (0);
		}
		if (sorted(stack_a))
		{
			free_stack(stack_a, argc);
			return (0);
		}
		if (ft_lstsize(stack_a) <= 5)
			small_sort(&stack_a, &stack_b);
		else
			big_sort(&stack_a, &stack_b);
		free_stack(stack_a, argc);
	}
	return (0);
}
