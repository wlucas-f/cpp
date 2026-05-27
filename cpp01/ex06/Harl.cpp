#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put"
              << " enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for"
              << " years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
    typedef void (Harl::*fptr)(void);
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    fptr ptr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int option;
    for(option = 0; option < 4; option++)
    {
        if(option == 3 && level != options[option])
        {
            option = -1;
            break ;
        }
        if(options[option] == level)
            break ;
    }

    switch(option){
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break ;
        case (DEBUG):
            (this->*ptr[DEBUG])();
            /* fallthrough */
        case (INFO):
            (this->*ptr[INFO])();
            /* fallthrough */
        case (WARNING):
            (this->*ptr[WARNING])();
            /* fallthrough */
        case (ERROR):
            (this->*ptr[ERROR])();
            break ;
    }
}