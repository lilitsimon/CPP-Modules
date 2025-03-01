#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) {}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " is distroyed." << std::endl;
}

void Zombie::announce() const {
	std::cout << name << " : BraiiiiiiinnnzzzZ... " << std::endl;
}
