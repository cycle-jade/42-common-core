#pragma once
#include <string>
#include <iostream>
#include <string>

class Weapon 
{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(const std::string& weaponType);
        ~Weapon(); 

        const std::string& getType() const;
        void setType(const std::string& weaponType);
};