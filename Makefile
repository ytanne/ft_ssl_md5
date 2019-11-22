# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 19:50:15 by yorazaye          #+#    #+#              #
#    Updated: 2019/11/21 21:39:16 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
SOURCE = src
INC = includes
LIB_INC = libft/includes
FT_C = main
FT_P = $(patsubst %, $(SOURCE)/%, $(addsuffix .c, $(FT_C)))
FT_O = $(addsuffix .o, $(FT_C))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "Compiling the libft"
	@make -C libft
	@echo "Compiling the ft_ssl binary"
	@gcc -o $(NAME) $(FT_P) -L libft -lft -I $(INC) -I $(LIB_INC) $(FLAGS)

clean:
	@echo "Delete object files in libft"
	@make clean -C libft

fclean: clean
	@echo "Deleting object and binary files and library in libft"
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
