#include "Harl.hpp"

int main(int argc, char **argv){
    if(argc != 2)
        return (1);
    Harl chato;
    std::string lvl(argv[1]);
    chato.complain(lvl);
//    chato.complain("DEBUG");
 //   chato.complain("INFO");
  //  chato.complain("ERROR");
}