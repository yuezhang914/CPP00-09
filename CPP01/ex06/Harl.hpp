#ifndef HARL_HPP
#define HARL_HPP

#include <string>

/*
** ex06 的 Harl：
** - levelToIndex：把字符串等级转成数字 0~3
** - filter：用 switch + fall-through 从某等级开始打印到最严重
*/
class Harl
{
public:
    Harl();
    ~Harl();

    void filter(const std::string &level);

private:
    int levelToIndex(const std::string &level) const;

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif
