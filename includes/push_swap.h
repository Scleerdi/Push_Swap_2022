/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:30:01 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/18 17:31:24 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	int				size_a;
	int				size_b;
	int				lead_a;
	int				lead_b;
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

# define OP_COUNT 11

typedef enum e_op
{
	e_sa,
	e_sb,
	e_ra,
	e_rb,
	e_rra,
	e_rrb,
	e_pa,
	e_pb,
	e_ss,
	e_rr,
	e_rrr,
}					t_op;

typedef struct s_pot
{
	int				rot_a;
	int				rot_b;
	struct s_pot	*next;
}					t_pot;

typedef void	(*t_operation)(t_stacks *);

int					get_highest_value_from_a(t_stacks const *ab);
int					push_lowest_value_to_b(t_stacks *ab);
int					push_swap(t_stacks *ab);
int					sorted(t_stacks *ab);
int					stack_sorted(t_stack **stack);
int					arg_check(t_stack *a, int data, char *argv);
int					value_exists(t_stack *a, int data);
int					init_tpot(t_pot **head, int rot_a, int rot_b);
int					error_delete_all(t_stacks *ab);
int					ft_a_is_int(char *n);
int					determine_tail(t_stacks const *ab);
int					determine_head(t_stacks const *ab);
void				execute(t_stacks *ab, t_op operation);
void				execute_c(t_stacks *ab, t_op operation);
void				bucket_sort(t_stacks *ab);
void				push_all_b_to_a(t_stacks *ab);
void				del_stacks(t_stack **astack_a, t_stack **astack_b);
void				dup_stack(t_stacks const *ab, t_stacks *dup_ab);
void				push_a(t_stacks *ab);
void				push_b(t_stacks *ab);
void				swap_a(t_stacks *ab);
void				swap_b(t_stacks *ab);
void				rotate_b(t_stacks *ab);
void				rotate_a(t_stacks *ab);
void				reverse_rotate_a(t_stacks *ab);
void				reverse_rotate_b(t_stacks *ab);
void				ss(t_stacks *ab);
void				rr(t_stacks *ab);
void				rrr(t_stacks *ab);
void				rot_calc(t_stacks *ab);
void				small_sort(t_stacks *ab);
void				delete_tpots(t_pot **head);
void				printstacks(t_stack *a, t_stack *b);
t_pot				*create_tpot(int rot_a, int rot_b);
t_pot				*get_stack_data(t_stacks *ab);
t_pot				*choose_pot(t_pot *pot);
t_stack				*create_node(int data);

#endif
