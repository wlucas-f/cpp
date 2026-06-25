#pragma once

#include <cctype>

template<typename T, typename F>
void iter(T *adr, const int len, F func){
	for(int i = 0; i < len; i++)
		func(adr[i]);
}
