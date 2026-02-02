#ifndef HARL_HPP
#define HARL_HPP

#include <string> // std::string

/*
** Harl 类
** 作用：根据不同 level（等级）输出不同的吐槽内容
**
** 题目重点：
** - complain(level) 必须使用“成员函数指针”（pointers to member functions）
** - 不能只是写一堆 if/else 去判断
*/
class Harl
{
public:
    Harl();
    ~Harl();

    /*
    ** complain
    ** 作用：根据 level 字符串，调用对应的私有函数：
    ** - "DEBUG"   -> debug()
    ** - "INFO"    -> info()
    ** - "WARNING" -> warning()
    ** - "ERROR"   -> error()
    **
    ** 参数：
    ** - level：等级字符串
    ** 返回：无
    */
    void complain(const std::string &level);

private:
    // 四个等级对应四个私有函数（题目要求）
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif
