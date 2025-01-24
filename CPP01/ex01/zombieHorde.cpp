#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
    if (N <= 0)
        std::cerr << "Error: the hord size must be greater than 0." << std::endl;
    
    Zombie *horde =  new Zombie[N];

    for (int i = 0; i < N; ++i) {
        horde[i] = Zombie(name); // using the constructor to initialise each zombie
    }

    return horde;
}
