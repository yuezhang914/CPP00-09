# =========================
# 文件用途：
#   这个 Makefile 用来“一键编译”你的 C++ 程序。
#   你只需要在 ex00 目录里输入：
#       make        -> 编译生成可执行文件 megaphone
#       make re     -> 先清理再重新编译
#       make clean  -> 删除中间产物 .o
#       make fclean -> 删除 .o 和 可执行文件
# =========================

# 最终生成的可执行文件名字（你运行时就是：./megaphone）
NAME		= megaphone

# 使用的编译器（c++ 通常等价于 clang++ 或 g++，以你机器配置为准）
CXX		= c++

# 编译参数（非常重要）
# -Wall -Wextra -Werror：把常见问题当成警告/错误（符合 42 要求）
# -std=c++98：保证用 C++98 标准编译（CPP Module 00 需要）
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# 删除命令（rm -f 表示：即使文件不存在也不报错）
RM		= rm -f

# 源文件列表（本题只有一个 megaphone.cpp）
SRCS		= megaphone.cpp

# 把 .cpp 自动映射成 .o（目标文件/中间文件）
# 例如 megaphone.cpp -> megaphone.o
OBJS		= $(SRCS:.cpp=.o)

# 默认目标：all
# 输入 make 时，默认就是执行 all
all: $(NAME)

# 目标：生成可执行文件 $(NAME)
# 依赖：所有 .o 文件都必须先生成
$(NAME): $(OBJS)
	# 链接：把 .o 文件链接成最终可执行程序
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# 模式规则：任何 .cpp 都可以用这个规则编译成 .o
# $< 表示第一个依赖文件（例如 megaphone.cpp）
# $@ 表示目标文件（例如 megaphone.o）
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean：删除中间文件（.o）
clean:
	$(RM) $(OBJS)

# fclean：先 clean 再删除可执行文件
fclean: clean
	$(RM) $(NAME)

# re：重新编译（先彻底清理，再 all）
re: fclean all

# .PHONY：告诉 make 这些名字是“命令”，不是文件名
.PHONY: all clean fclean re
