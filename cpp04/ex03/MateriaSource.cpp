#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource(){
    for(int i = 0; i < 4; i++) slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other){
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other){
    if(this != &other)
        *this = other;
    return *this;
}

MateriaSource::~MateriaSource(){
    for(int i = 0; i < 4; i++){
        if(slot[i]){
            delete slot[i];
            slot[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* mat){
    int i = 0;
    while (slot[i] && i < 4)
        i++;
    if(i <=3)
        slot[i] = mat;
    else
        delete mat;
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
    if (type == "cure"){
        nMat = new Cure;
        return nMat;
    }
    return 0;
}
