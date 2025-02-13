#include "Dog.hpp"

Dog::Dog() : brain(new Brain()){
    type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)){
    std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    if(this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog(){
    delete brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!" << std::endl;
}
