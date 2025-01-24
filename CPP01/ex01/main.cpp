#include "Zombie.hpp"

int main(){
    int hordeSize = 7;
    Zombie *horde = zombieHorde(hordeSize, "HordeZombie");

    if(horde == nullptr)
        return 1;

    for (int i = 0; i < hordeSize; ++i)
        horde[i].announce();

delete[] horde;

return 0;
}
