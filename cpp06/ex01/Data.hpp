#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data{
    private:
        std::string _model;
        int _year;
    public:
        Data();
        Data(std::string model, int year);
        Data(const Data &other);
        Data &operator=(const Data &other);
        void printData();
        ~Data();
};

#endif
