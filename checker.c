/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:01:07 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 14:25:47 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_input_sub(t_list **s_a, t_list **s_b, char *line)
{
	int	res;

	res = 0;
	if (!ft_strcmp(line, "pa\n"))
	{
		res = 1;
		pa(s_a, s_b, 1);
	}
	else if (!ft_strcmp(line, "pb\n"))
	{
		res = 1;
		pb(s_a, s_b, 1);
	}
	return (res);
}

int	check_input(t_list **stack_a, t_list **stack_b, char *line)
{
	int	res;

	res = 1;
	if (!ft_strcmp(line, "sa\n"))
		sa(*stack_a, 1);
	else if (!ft_strcmp(line, "sb\n"))
		sb(*stack_b, 1);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stack_a, 1);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stack_b, 1);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stack_a, 1);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stack_b, 1);
	else if (!ft_strcmp(line, "ss\n"))
		ss(*stack_a, *stack_b, 1);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b, 1);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b, 1);
	else if (!check_input_sub(stack_a, stack_b, line))
		res = 0;
	return (res);
}

int	parse_std_input(t_list **stack_a, t_list **stack_b, int argc)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_input(stack_a, stack_b, line))
		{
			free_stack(*stack_a, argc);
			free_stack(*stack_b, argc);
			free(line);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
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
		if (!stack_a)
		{
			if (!stack_a)
				ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (!parse_std_input(&stack_a, &stack_b, argc))
			return (0);
		if (sorted(stack_a) && !stack_b)
			ft_putstr_fd("OK\n", FD);
		else
			ft_putstr_fd("KO\n", FD);
		free_stack(stack_a, argc);
		free_stack(stack_b, argc);
	}
	return (0);
}
