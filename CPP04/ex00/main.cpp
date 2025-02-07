#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
    const Animal* meta = new Animal(); // base class pointer that points to an Animal object.
    const Animal* dog = new Dog(); // base class pointer that points to a Dog object.
    const Animal* cat = new Cat(); //  base class pointer that points to a Cat object.

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "Nesting WrongAnimal and WrongCat" << std::endl;
    const WrongAnimal* wCat = new WrongCat();
    wCat->makeSound();
    delete wCat;

    return 0;
}
