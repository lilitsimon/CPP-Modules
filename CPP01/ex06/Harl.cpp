#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << " [ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
    std::cout << " [ INFO ]\n I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << " [ WARNING ]\n I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << " [ ERROR ]\n This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    int levelIndex = -1;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if(levels[i] == level) {
            levelIndex = i;
            break;
        }
    }

    switch(levelIndex){
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    
}

