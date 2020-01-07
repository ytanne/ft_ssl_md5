# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 19:50:15 by yorazaye          #+#    #+#              #
#    Updated: 2020/01/06 21:00:21 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
SOURCE = src
INC = includes
LIB_INC = libft/includes
FT_C = main ft_md5 auxilary_functions prints_handling input_structure\
	extra_functions flag_operations printing_function pqrs_flags
FT_P = $(patsubst %, $(SOURCE)/%, $(addsuffix .c, $(FT_C)))
FT_O = $(addsuffix .o, $(FT_C))
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "Compiling the libft"
	@make -C libft
	@echo "Compiling the ft_ssl binary"
	@gcc -o $(NAME) $(FT_P) -L libft -lft -I $(INC) -I $(LIB_INC) $(FLAGS)

debug:
	@echo "Initiating debuging"
	@gcc -o $(NAME) $(FT_P) -L libft -lft -I $(INC) -I $(LIB_INC) $(FLAGS) -g

clean:
	@echo "Delete object files in libft"
	@rm -rf ft_ssl.dSYM
	@make clean -C libft

fclean: clean
	@echo "Deleting object and binary files and library in libft"
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
