#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default"){
        _hitPoints = 100;
        _energyPoints = 100;
        _attackDamage = 30;
        std::cout << "FragTrap Default Constuctor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
        _hitPoints = 100;
        _energyPoints = 100;
        _attackDamage = 30;
        std::cout << "FragTrap " << _name << " is created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap Copy Constructor called!" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap Copy Assignment Operator Created!" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other); //using ClapTraps assignment operator;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << _name << " requests a HIGH FIVE!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}





