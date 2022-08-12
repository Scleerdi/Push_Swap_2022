/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:31:25 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/08/12 15:28:38 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Converts the written commands to executable commands
**	Executes those commands on the stacks
*/

int	convert_to_command(t_stacks *ab, char *line)
{
	if (ft_strequ(line, "sa"))
		execute_c(ab, e_sa);
	else if (ft_strequ(line, "sb"))
		execute_c(ab, e_sb);
	else if (ft_strequ(line, "ra"))
		execute_c(ab, e_ra);
	else if (ft_strequ(line, "rb"))
		execute_c(ab, e_rb);
	else if (ft_strequ(line, "rra"))
		execute_c(ab, e_rra);
	else if (ft_strequ(line, "rrb"))
		execute_c(ab, e_rrb);
	else if (ft_strequ(line, "pa"))
		execute_c(ab, e_pa);
	else if (ft_strequ(line, "pb"))
		execute_c(ab, e_pb);
	else if (ft_strequ(line, "ss"))
		execute_c(ab, e_ss);
	else if (ft_strequ(line, "rr"))
		execute_c(ab, e_rr);
	else if (ft_strequ(line, "rrr"))
		execute_c(ab, e_rrr);
	else
		return (0);
	return (1);
}

/*
**	Calls convert_to_command and reads the input supplied by the user
*/

int	checker(t_stacks *ab)
{
	char	*line;
	int		ret;

	line = ft_strdup("");
	ret = 1;
	while (line)
	{
		line = ft_get_next_line(0);
		if (!line)
			return (-1);
		if (convert_to_command(ab, line) == 0 && *line != '\0')
		{
			free(line);
			return (2);
		}
		free(line);
	}
	if (sorted(ab) == 0)
		return (0);
	return (1);
}

/*
**	Assists the Main
**	Errors if appropriate
*/

static	int	loop(t_stacks *ab, char *str)
{
	t_stack		*current;

	if (arg_check(ab->a, ft_atoi(str), str))
		return (error_delete_all(ab));
	current = create_node(ft_atoi(str));
	if (!current)
		return (error_delete_all(ab));
	if (ab->a == NULL)
		ab->a = current;
	else
	{
		current->next = ab->a;
		ab->a = current;
	}
	return (0);
}

/*
**	Calls checker
**	Checks the conditions of the stacks after checker has returned
*/

void	declare(t_stacks *ab)
{
	int	ret;

	if (ab->size_a != 0)
	{
		ret = checker(ab);
		if (ret == 2 && sorted(ab) == 0)
			ft_putendl_fd("KO", 1);
		else if (ret == 2 && sorted(ab) == 1)
			error_delete_all(ab);
		else if (ret == 0)
			ft_putendl_fd("KO", 1);
		else if (ret == -1)
			error_delete_all(ab);
		else
			ft_putendl_fd("OK", 1);
	}
}

/*
**	Initiates the struckt that holds stacks A and B
**	Checks for duplicate input and non numerical imput
**	Calls Declare
*/

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	ab;

	ft_bzero(&ab, sizeof(t_stacks));
	i = argc - 1;
	ab.size_a = argc - 1;
	while (i > 0)
	{
		if (loop(&ab, argv[i]) == 1)
		{
			del_stacks(&ab.a, &ab.b);
			return (1);
		}
		i--;
	}
	declare(&ab);
	del_stacks(&ab.a, &ab.b);
	return (0);
}
