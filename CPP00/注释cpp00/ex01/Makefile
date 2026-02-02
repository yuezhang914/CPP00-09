# =========================
# 文件用途：
#   一键编译 ex01 的电话本程序。
#   make        -> 编译生成 phonebook（可执行文件）
#   make re     -> 清理后重编
#   make clean  -> 删除 .o
#   make fclean -> 删除 .o 和 可执行文件
# =========================

NAME        = phonebook

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
RM          = rm -f

# 头文件目录（include）
INCLUDES    = -Iincludes

# 源文件列表（注意：这里写的是你 src 目录下的 .cpp）
SRCS        = src/main.cpp \
              src/PhoneBook.cpp \
              src/Contact.cpp

# 把 .cpp 映射成 .o（中间文件）
OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

# 链接：把所有 .o 合成最终可执行文件
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

# 编译：把每个 .cpp 编译成对应的 .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
