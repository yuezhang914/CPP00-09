#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

/*
** main
** 作用：按题目示例方式测试 HumanA/HumanB
** 注意：
** - HumanA 必须在构造时给武器
** - HumanB 可以先不拿武器，后面 setWeapon
*/
int main(void)
{
    // ===== 第一段：HumanA（永远有武器）=====
    {
        Weapon club("crude spiked club");
        HumanA bob("Bob", club);

        bob.attack();

        // 改武器类型：HumanA 的武器是引用，会自动“看到变化”
        club.setType("some other type of club");
        bob.attack();
    }

    // ===== 第二段：HumanB（可能没武器）=====
    {
        Weapon club("crude spiked club");
        HumanB jim("Jim");

        // 没武器也不会崩溃
        jim.attack();

        // 现在给他武器
        jim.setWeapon(club);
        jim.attack();

        // 改武器类型：HumanB 保存的是武器地址，也能看到变化
        club.setType("some other type of club");
        jim.attack();
    }

    return 0;
}
