# =========================
# 文件用途：
#   一键编译 ex02（Account）：
#     make    -> 生成可执行文件 account
#     make re -> 清理后重新编译
# =========================

# 最终可执行文件名（我这里用 account，更直观；题目不强制必须叫 tests）
NAME		= account

# 编译器
CXX		= c++

# 编译参数（评估表会检查这些）
# -Wall -Wextra -Werror：把警告当错误（更严格）
# -std=c++98：符合 CPP Module 00 的要求
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# 删除命令
RM		= rm -rf

# 源文件：tests.cpp 会调用你的 Account 类
SRCS		= tests.cpp Account.cpp

# 目标文件（中间文件）
OBJS		= $(SRCS:.cpp=.o)

# 头文件在当前目录，用 -I. 告诉编译器去哪里找
INCLUDES	= -I.

all: $(NAME)

# 链接：把 .o 合成可执行文件
$(NAME): $(OBJS) Account.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

# 编译：把 .cpp 编译成 .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
