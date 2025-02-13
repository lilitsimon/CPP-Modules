#include "Cat.hpp"

Cat::Cat() :brain(new Brain()){
    type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)){
    std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    if(this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat(){
    delete brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow meow!" << std::endl;
}
