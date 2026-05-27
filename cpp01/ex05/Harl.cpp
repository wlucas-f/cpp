#include "Harl.hpp"

void Harl::complain(std::string level){
    typedef void (Harl::*fptr)(void);
    std::string options[4]{"DEBUG", "INFO", "WARNING", "ERROR"};

    fptr ptr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++){
        if (level == options[i])
            (this->*ptr[i])();
    }
}