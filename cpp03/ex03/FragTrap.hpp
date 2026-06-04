#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        explicit FragTrap(const std::string name);
        FragTrap(FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        void highFiveGuys(void);
        bool chassisUp();
        ~FragTrap();
};

#endif
