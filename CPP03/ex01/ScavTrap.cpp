#include "ScavTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default"){
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
        std::cout << "ScavTrap Default Constuctor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
        std::cout << "ScavTrap " << _name << " is created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap Copy Constructor called!" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "ScavTrap Copy Assignment Operator Created" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other); //using ClapTraps assignment operator;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target){
    if (_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }

    _energyPoints--;
    std::cout << "ScavTrap " << _name << " viciously attacks " << target 
                << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::guardGate(){
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}




