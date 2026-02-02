#ifndef HARL_HPP
#define HARL_HPP

#include <string>

/*
** Harl：一个会按等级抱怨的人
** complain(level)：根据 level 选择对应的私有函数去打印
*/
class Harl
{
public:
    Harl();
    ~Harl();

    /*
    ** level：只能是 "DEBUG" "INFO" "WARNING" "ERROR"
    ** 如果不匹配任何等级，这里就什么也不输出（按 ex05 通常做法）
    */
    void complain(const std::string &level);

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif
