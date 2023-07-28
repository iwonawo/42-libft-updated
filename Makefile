# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 12:11:53 by iwozniak          #+#    #+#              #
#    Updated: 2023/07/28 12:44:08 by iwozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_strlen \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_strnstr \
		ft_strlcpy \
		ft_strlcat \
		ft_atoi \
		ft_strdup \
		ft_calloc \
		ft_bzero \
		ft_memset \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd

CFILES_BONUS = \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(CFILES)))
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(CFILES_BONUS)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

HDR_NAMES = libft.h
HDR_FOLDER = ./includes/
HDRS = $(addprefix $(HDR_FOLDER), $(HDR_NAMES))
HDR_INC = $(addprefix -I, $(HDR_FOLDER))

$(NAME): $(OBJS) $(HDRS)
	$(AR) $@ $^

$(OBJS_DIR)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $(HDR_INC) -o $@ $<

all: $(NAME) $(HDRS)

bonus: $(OBJS) $(OBJS_BONUS) $(HDRS)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

libft.h: $(HDR_FOLDER)libft.h
	@cp $(HDR_FOLDER)libft.h .

.PHONY: bonus all clean fclean re
