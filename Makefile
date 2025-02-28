# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 19:24:02 by dacastil          #+#    #+#              #
#    Updated: 2025/02/24 18:34:33 by dacastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = libmlx_Linux.a -lX11 -lXext -lm # -fsanitize=address
EXEC = fdf
RM = rm -f
SCRS = fdf.c get_next_line_utils_bonus.c get_next_line_bonus.c ft_split.c \
			ft_substr.c ft_strlcpy.c fdf_1.c ft_strdup.c ft_strchr.c fdf_3.c \

OBJ = $(SRC:.c=.o)
INCLUDE = fdf.h

all = $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(EXEC)

re: fclean $(EXEC)

.PHONY: all clean fclean re


