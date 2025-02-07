#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== ClapTrap Test ===" << std::endl;
    ClapTrap clap("CLAP");
    clap.attack("TARGET");
    clap.takeDamage(3);
    clap.beRepaired(5);

    std::cout << "\n=== ScavTrap Test ===" << std::endl;
    FragTrap scav("SCAV");
    scav.attack("TARGET");
    scav.guardGate();
    scav.takeDamage(20);
    scav.beRepaired(10);

    return 0;
}
