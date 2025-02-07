#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Default Constuctor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : 
    _name(other._name + "_copy"),
    _hitPoints(other._hitPoints),
    _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap Copy Constructor called!" << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap Copy Assignment Operator called!" << std::endl;
    if (this != &other){
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}


void ClapTrap::attack(const std::string& target) {
    if(_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no hit points left to attack!" << std::endl;
        return;
    }
    if(_energyPoints == 0){
        std::cout << "Claprap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
            << _attackDamage << " points of damage! " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if(_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already distoyed " << std::endl;
        return;
    }

    if (amount >= _hitPoints)
        _hitPoints = 0;
    else  
        _hitPoints -= amount;
    
    std::cout << "ClapTrap " << _name << " takes " << amount 
        << " points of damage! Remaining HP: " << _hitPoints << std::endl; 

}

void ClapTrap::beRepaired (unsigned int amount) {
    if (_hitPoints == 0){
        std::cout << "ClapTrap " << _name << " can't be repaired, it's destroyed!" << std::endl;
        return;
    }
    if(_energyPoints == 0){
        std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
        return;
    }

    _energyPoints--;
    _hitPoints +=amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
                << " hit points! New HP: " << _hitPoints << std::endl;
}
