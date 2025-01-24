#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& weapon; //cannot be null

    public:
        HumanA(const std::string& name, Weapon& weapon);

        void attack() const;
};

#endif

