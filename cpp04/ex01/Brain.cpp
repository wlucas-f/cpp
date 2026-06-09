#include "Brain.hpp"

Brain::Brain() : ideas(){
    std::cout << "Brain default construtor called\n";
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy construtor called\n";
    *this = other;
}

Brain &Brain::operator=(const Brain &other){
    std::cout << "Brain assignment operator called\n";
    if (this == &other)
        return *this;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}

void Brain::setIdea(int index, const std::string &idea){
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index){
    return (this->ideas[index]);
}

Brain::~Brain(){
    std::cout << "Brain destructor called\n";
}
