#include "ClapTrap.hpp"

int main() {
    ClapTrap robot1("CLAP1");
    ClapTrap robot2(robot1);
    ClapTrap robot3;
    robot3 = robot1;

    robot1.attack("CLAP2");

    robot1.takeDamage(5);
    robot1.takeDamage(10); // Should drop HP to 0

    robot1.beRepaired(5); // Should not work if HP is 0

    return 0;
}
