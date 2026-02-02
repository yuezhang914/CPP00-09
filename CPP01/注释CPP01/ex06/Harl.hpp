#ifndef HARL_HPP
#define HARL_HPP

#include <string> // std::string

/*
** ex06 的目标：
** - 输入一个等级 level
** - 输出从该等级开始，到更严重等级的所有信息
**
** 关键点：
** - 题目提示用 switch
** - 但是 switch 不能直接 switch 字符串
**   所以我们需要先把字符串转换成数字（0~3）
*/
class Harl
{
public:
    Harl();
    ~Harl();

    /*
    ** filter
    ** 作用：根据 level 输出一组内容（从该 level 到 ERROR）
    ** 参数：
    ** - level：输入的等级字符串
    */
    void filter(const std::string &level);

private:
    /*
    ** levelToIndex
    ** 作用：把 "DEBUG/INFO/WARNING/ERROR" 转成 0/1/2/3
    ** 参数：
    ** - level：等级字符串
    ** 返回：
    ** - 0~3：合法等级
    ** - -1：不合法
    */
    int levelToIndex(const std::string &level) const;

    // 四个等级对应输出函数
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif
