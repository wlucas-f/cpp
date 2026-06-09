#include "Brain.hpp"

Brain::Brain() : ideas(){
    std::cout << "Brain default construtor called\n";
}

Brain &Brain::operator=(const Brain &other){
    std::cout << "Brain assignment operator called\n";
    if (this != &other){
	    for(int i = 0; i < 100; i++)
	        this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy construtor called\n";
    if (this != &other){
	    for(int i = 0; i < 100; i++)
	        this->ideas[i] = other.ideas[i];
    }
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
