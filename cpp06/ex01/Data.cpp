#include "Data.hpp"
#include <iostream>

Data::Data():_model("Default"), _year(1985){}

Data::Data(std::string model, int year):_model(model), _year(year){}

Data::Data(const Data &other):_model(other._model), _year(other._year){}

Data &Data::operator=(const Data &other){
    if(this != &other)
    {
        _model = other._model;
        _year = other._year;
    }
    return *this;
}

void Data::printData(){
    std::cout << "model: "+_model+"\n";
    std::cout << "year: " << _year << "\n";
}

Data::~Data(){}
