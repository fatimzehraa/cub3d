# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 17:00:48 by fael-bou          #+#    #+#              #
#    Updated: 2021/12/17 21:49:18 by fael-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libft.a
M_OBJS	= ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o

B_OBJS = ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o 

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc

all : $(NAME)

$(NAME) : $(M_OBJS)
	$(AR) $(ARFLAGS) $@ $^ 

bonus : $(B_OBJS) $(M_OBJS) 
	$(AR) $(ARFLAGS) $(NAME) $^ 


%.o : %.c libft.h 
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(M_OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
