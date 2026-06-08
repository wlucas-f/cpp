#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource(){}

MateriaSource::MateriaSource(const MateriaSource &other){
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other){
    if(this != &other)
        *this = other;
    return *this;
}

MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria* mat){
    int i = 0;
        while (slot[i] && i < 4)
            i++;
        if(i <=3)
            slot[i] = mat;
}

AMateria* MateriaSource::createMateria(std::string const & type){
    int i = 0;
    while(slot[i])
        i++;
    AMateria *nMat = slot[i];
    if(type == "ice"){
        nMat = new Ice;
        return nMat;
    }
    else if (type == "cure"){
        nMat = new Cure;
        return nMat;
    }
    else
        return 0;
}
