#include "Brain.hpp"

Brain::Brain() : ideas(){
    std::cout << "Brain construtor called\n";
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy construtor called\n";
    *this = other;
}

Brain &Brain::operator=(const Brain &other){
    std::cout << "Brain assignment operator called\n";
    if (this == &other)
        return *this;
    this->setArrIdeas(other.getArrIdeas());
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destructor called\n";
}
