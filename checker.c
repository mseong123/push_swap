/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:01:07 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 10:31:15 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			if (!stack_a)
				ft_putstr_fd("Error\n", FD);
			return (0);
		}	
	}
	return (0);
}

