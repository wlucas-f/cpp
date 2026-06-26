#include "Base.hpp"

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <ctime>
#include <exception>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
	Base *ret;

	srand((unsigned) time(NULL));
	int random = (rand()%3);
	if(random == 0)
		ret = new A;
	if(random == 1)
		ret = new B;
	if(random == 2)
		ret = new C;
	return ret;
}

void identify(Base* p){
	if(p == NULL){
		std::cout << "Pointer is NULL" << std::endl;
		return;
	}
	if(dynamic_cast<A*>(p) != NULL)
		std::cout << "It's A!\n";
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << "It's B!\n";
	else if(dynamic_cast<C*>(p) != NULL)
		std::cout << "It's C!\n";
	else
		std::cout << "Unknown type\n";
}

void identify(Base& p){
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It's A!\n";
		return;
	}catch(std::exception &e){}
	try{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "It's B!\n";
		return;
	}catch(std::exception &e){}
	try{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "It's C!\n";
		return;
	}catch(std::exception &e){}
}

int main(){
	Base *Bs = generate();
	A a;
	B b;
	C c;

	identify(Bs);
	identify(a);
	identify(b);
	identify(c);

	delete Bs;
}
