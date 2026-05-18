#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    public:
        Weapon(){};
        Weapon(std::string t) : type(t){};
        const std::string& getType(){
            return(type);
        };
        void setType(std::string t){
           type = t; 
        }
    private:
        std::string type;
};

#endif