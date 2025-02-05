#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default"){
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
        std::cout << "ScavTrap Default Constuctor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
        std::cout << "ScavTrap " << _name << " is created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap Copy Constructor called!" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap Copy Assignment Operator Created!" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other); //using ClapTraps assignment operator;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target){
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

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}




