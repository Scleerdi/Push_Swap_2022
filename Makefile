# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: scleerdi <scleerdi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/05 15:03:44 by scleerdi      #+#    #+#                  #
#    Updated: 2022/07/20 14:17:28 by scleerdi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAMEP = push_swap
NAMEC = checker
SRCP = push_swap create_node sorted stack_sorted dup_stack del_stacks \
push_stack swap_stack rotate_stack reverse_rotate_stack execute small_sort  \
bucket_sort rot_calc high low finalize get_stack_data t_pot_list_tools choose_pot \
arg_check error_delete_all printstacks
SRCC = checker create_node del_stacks sorted stack_sorted execute_c \
swap_stack rotate_stack reverse_rotate_stack push_stack \
error_delete_all arg_check printstacks 
SRCP := $(SRCP:%=srcs/source/%.c)
OBJP = $(SRCP:%.c=%.o)
SRCC := $(SRCC:%=srcs/source/%.c)
OBJC = $(SRCC:%.c=%.o)
INC = -I srcs/libft/includes/ -I includes/
FLAGS = -g -Wall -Werror -Wextra

all: $(NAMEP) $(NAMEC)

$(NAMEP): $(OBJP)
	@make -C srcs/libft/
	@$(CC) -o $(NAMEP) $(FLAGS) $(OBJP) $(INC) -Lsrcs/libft -lft

$(NAMEC): $(OBJC)
	@make -C srcs/libft/
	@$(CC) -o $(NAMEC) $(FLAGS) $(OBJC) $(INC) -Lsrcs/libft -lft	

%.o: %.c
	@echo "Compiling $(shell basename $<)"
	@$(CC) -o $@ $(FLAGS) $(INC) -c $<

clean:
	@-rm -f $(OBJP) $(OBJC)
	@make -C srcs/libft/ clean

fclean: clean
	@-rm -f $(NAMEP) $(NAMEC)
	@make -C srcs/libft/ fclean

re: fclean all
