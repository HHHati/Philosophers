# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Bade-lee <bade-lee@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 16:00:45 by Bade-lee          #+#    #+#              #
#    Updated: 2022/09/03 16:26:44 by Bade-lee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I pipex.h

#          ----------========== {     SRCS     } ==========----------

SRC =\
		philosophers.c\

#          ----------========== {     OBJS     } ==========----------

OBJ_DIR = obj_dir/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#          ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@printf "\e[1;42m \e[0;m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf obj_dir
	@printf "\e[0;31m[.o files deleted]\n\e[0;m"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[0;31m[philo deleted]\n\e[0;m"

re: fclean all

.PHONY: all clean fclean re