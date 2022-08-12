# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: scleerdi <scleerdi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/08 14:23:00 by scleerdi      #+#    #+#                  #
#    Updated: 2022/08/12 15:47:50 by scleerdi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE = strequ atoi bzero isalnum isalpha isascii isdigit isprint abs isblank \
		putchar_fd putendl_fd putnbr_fd putstr_fd strchr strjoin strlcpy \
		strlen strnstr tolower toupper strcpy memset memmove memcpy \
		strrchr strcmp strncmp strlcat memchr memcmp calloc strdup strndup \
		substr strcat strtrim itoa split strmapi striteri isspace \
		isupper islower strnew num_len strnlen strclen get_next_line \
		lstnew lstadd_front lstsize lstadd_back itoa_base printf \
		lstlast lstiter lstdelone lstclear lstmap sort_int_tab \
		puthex_fd utoa_base a_is_int min max memalloc   \

SOURCE := $(SOURCE:%=ft_%.c)
OBJECT := $(SOURCE:%.c=%.o)
INC = -I ./includes

all: $(NAME)

$(NAME): $(OBJECT)
	@echo "Compiling Libft"
	@gcc -Wall -Werror -Wextra -c $(SOURCE) -I ./includes
	@ar -rcs $(NAME) $(OBJECT)

$(OBJECT): $(SOURCE)
	@gcc -Wall -Werror -Wextra -c $(SOURCE) $(INC)

clean:
	@-rm -f $(OBJECT)

fclean: clean
	@-rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
