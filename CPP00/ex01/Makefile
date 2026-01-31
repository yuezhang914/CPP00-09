# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 22:28:04 by yzhang2           #+#    #+#              #
#    Updated: 2026/01/30 22:28:05 by yzhang2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	phonebook

SRC_DIR		=	./src/
OBJ_DIR		=	obj/

INCS_DIR	=	includes
MAIN_INC	= -I $(INCS_DIR)
INCS		=	$(shell find $(INCS_DIR) -type f -name "*.hpp")

SRC			=	main.cpp \
				PhoneBook.cpp \
				Contact.cpp
				
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
		@mkdir -p $(OBJ_DIR)
		$(CC) ${CFLAGS}  $(MAIN_INC) -o $@ -c $<

$(NAME)		:	$(OBJ) $(INCS)
		$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)
					
all			:	$(NAME)

clean		:
		@rm -rf $(OBJ_DIR)

fclean		:	clean
		@rm -rf $(NAME)

re			:	fclean	all

.PHONY		:	all clean fclean re