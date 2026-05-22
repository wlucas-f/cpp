#ifndef WEAPON_HPP 
#define WEAPON_HPP 

#include <iostream>

class Weapon{
    public:
        Weapon(const std::string &type) : type(type){};
        const std::string &getType() const{
            return (this->type);
        }
        void setType(std::string type){
            this->type = type;
        }
    private:
        std::string type;
};

#endif