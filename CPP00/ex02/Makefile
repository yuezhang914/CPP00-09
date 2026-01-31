# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 22:28:38 by yzhang2           #+#    #+#              #
#    Updated: 2026/01/30 22:33:30 by yzhang2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		= account

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

SRCS		= tests.cpp Account.cpp
OBJS		= $(SRCS:.cpp=.o)

INCLUDES	= -I.

all: $(NAME)

$(NAME): $(OBJS) Account.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
