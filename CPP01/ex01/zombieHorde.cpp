#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cerr << "Error: the horde size must be greater than 0." << std::endl;
        return NULL;
    }

    Zombie *horde = new Zombie[N]; // Calls the default constructor

    for (int i = 0; i < N; ++i) {
        new (&horde[i]) Zombie(name);  // Placement new: construct zombie in allocated memory
    }

    return horde;
}

