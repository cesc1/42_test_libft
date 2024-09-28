# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faguirre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 18:07:16 by faguirre          #+#    #+#              #
#    Updated: 2024/09/19 17:05:42 by faguirre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = a.out

LIB_DIR = $(shell cd ..; pwd)
TEST_DIR = srcs
OBJECTS_DIR = objects
INCLUDES_DIR = includes

LIB_NAME = $(LIB_DIR)/libft.a
SRCS = test_ft_itoa.c \
       test_ft_memset.c \
       test_ft_strlcat.c \
       test_ft_strtrim.c \
       test_ft_put.c \
       test_ft_strlcpy.c \
       test_ft_substr.c \
       test_ft_split.c \
       test_ft_strlen.c \
       test_ft_tolower.c \
       test_ft_atoi.c \
       test_ft_memchr.c \
       test_ft_strchr.c \
       test_ft_strmapi.c \
       test_ft_toupper.c \
       test_ft_bzero.c \
       test_ft_memcmp.c \
       test_ft_strdup.c \
       test_ft_strncmp.c \
       test_ft_calloc.c \
       test_ft_memcpy.c \
       test_ft_striteri.c \
       test_ft_strnstr.c \
       test_ft_is.c \
       test_ft_memmove.c \
       test_ft_strjoin.c \
       test_ft_strrchr.c

BONUS = test_ft_lstnew.c \
	test_ft_lstadd_front.c \
	test_ft_lstsize.c \
	test_ft_lstlast.c \
	test_ft_lstadd_back.c \
	test_ft_lstdel.c \
	test_ft_lstiter.c \
	test_ft_lstmap.c

OBJS = $(patsubst %.c, $(OBJECTS_DIR)/%.o, $(SRCS) main.c)
BONUS_OBJS = $(patsubst %.c, $(OBJECTS_DIR)/%.o, $(SRCS) $(BONUS) main_bonus.c)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(LIB_DIR) -g
CFLAGS_LIBFT = -L$(LIB_DIR) -lft


all: $(NAME) 

$(NAME): $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(CFLAGS_LIBFT)

$(LIB_NAME):
	cd ..; make

$(OBJECTS_DIR)/%.o: $(TEST_DIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

bonus: $(BONUS_OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) -o a.out $(BONUS_OBJS) $(CFLAGS_LIBFT)

.PHONY: all clean fclean bonus
