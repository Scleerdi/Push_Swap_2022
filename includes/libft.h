/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 12:13:07 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/08/12 15:47:28 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putstr(const char *s);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_striter(char *s, void (*f)(char *));
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_sort_int_tab(int *tab, unsigned int size);
char			*ft_get_next_line(const int fd);
char			*ft_strnew(size_t size);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strdup(const char *src);
char			*ft_itoa(int n);
char			*ft_itoa_base(intmax_t value, intmax_t base);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			**ft_strsplit(const char *s, char c);
int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isblank(int c);
int				ft_isspace(int c);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				get_next_line(const int fd, char **line);
int				ft_sqrt(int nb);
size_t			ft_strlen(const char *str);
size_t			ft_strlend(const char *str, const int fd);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
intmax_t		ft_abs(intmax_t a);
intmax_t		ft_intlen(intmax_t n);

#endif
