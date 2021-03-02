# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 17:09:29 by da-lee            #+#    #+#              #
#    Updated: 2020/11/13 11:23:39 by da-lee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		libft.a
CC				=		gcc
CFLAGS			= 		-Wall -Wextra -Werror 
RM				=		rm -f
AR				=		ar rcs

SRCS			=		ft_isascii.c ft_strlen.c ft_toupper.c \
						ft_isalpha.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_isalnum.c \
						ft_putnbr_fd.c ft_putendl_fd.c\
						ft_putstr_fd.c ft_putchar_fd.c ft_strmapi.c ft_split.c \
						ft_strtrim.c ft_strjoin.c ft_itoa.c ft_substr.c ft_strdup.c \
						ft_calloc.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c \
						ft_memcpy.c ft_bzero.c ft_memset.c ft_atoi.c ft_strncmp.c \
						ft_strnstr.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \

BONUS			= 		ft_lstmap.c ft_lstclear.c ft_lstiter.c \
						ft_lstadd_front.c ft_lstnew.c \
						ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c

OBJS			=		$(SRCS:.c=.o)

BONUS_OBJS		=		$(BONUS:.c=.o)


$(NAME)			:		$(OBJS)
							$(AR) $(NAME) $(OBJS)
 
all				:		$(NAME)

clean			:
							$(RM) $(OBJS) $(BONUS_OBJS)

fclean			:		clean
							$(RM) $(NAME)

re				:		fclean all

bonus			:		$(BONUS_OBJS)
							$(AR) $(NAME) $(BONUS_OBJS)

.PHONY			:		all clean fclean re bonus
