#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== ClapTrap Test ===" << std::endl;
    ClapTrap clap("CLAP");
    clap.attack("TARGET");
    clap.takeDamage(3);
    clap.beRepaired(5);

    std::cout << "\n=== ScavTrap Test ===" << std::endl;
    ScavTrap scav("SCAV");
    scav.attack("TARGET");
    scav.guardGate();
    scav.takeDamage(20);
    scav.beRepaired(10);

    std::cout << "\n=== FragTrap Test ===" << std::endl;
    FragTrap frag("FRAG");
    frag.attack("TARGET");
    frag.highFivesGuys();
    frag.takeDamage(50);
    frag.beRepaired(30);

    return 0;
}
