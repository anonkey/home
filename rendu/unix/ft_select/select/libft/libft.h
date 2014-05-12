/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:21:16 by tseguier          #+#    #+#             */
/*   Updated: 2014/01/10 03:15:31 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include "ft_ldcd_cell.h"
# define BUFF_SIZE 1000000

typedef struct				s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}							t_list;

typedef struct				s_ldcd
{
	struct s_ldcd_cell	*head;
	struct s_ldcd_cell	*tail;
	size_t				size;
}							*t_ldcd;

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst,void (*del)(void *, size_t));
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t		ft_lstsize(t_list *lst);
t_ldcd		ft_ldcdnew(void);
void		*ft_ldcdpop(t_ldcd ldcd, t_ldcd_cell cell);
void		*ft_ldcdpop_back(t_ldcd ldcd);
void		*ft_ldcdpop_front(t_ldcd ldcd);
int			ft_ldcdpush_back(t_ldcd ldcd, void *elem, size_t content_size);
int			ft_ldcdpush_front(t_ldcd ldcd, void *elem, size_t content_size);
void		ft_ldcddel(t_ldcd *ldcd, void (*del)(void **));
void		ft_ldcditer(t_ldcd ldcd, void (*f)(void *elem, size_t elemsize));
int			ft_ldcdsize(t_ldcd ldcd);
size_t		ft_ldcdat(t_ldcd ldcd, const void **at, unsigned int i);
void		ft_ldcddel_head(t_ldcd ldcd);
void		ft_ldcddel_tail(t_ldcd ldcd);
int			ft_strcsub(char **dst, char *src, unsigned int start, char end);
int			ft_strsepjoin(char **dir, char *name, char *sep);
char		**ft_strtabcpy(char **strtab, int addsize);
int			ft_strtabrealloc(char ***strtab, int addsize);
void		ft_strtabdel(char ***strtab);
int			get_next_line(int const fd, char ** line);

#endif
