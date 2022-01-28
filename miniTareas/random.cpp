#include<iostream>

const long a = 1664525;
const long c = 1013904223;
const long m = 4294967296;

long get_random(long & current){
	current = (a*current + c)%m;
	return current;
}

int main(int argc, char const *argv[])
{
	long current = 1;
	for(int iter = 0; iter < 10000; ++iter){
		std::cout << get_random(current)/double(m-1) << "\t" 
		<< get_random(current)/double(m-1) << "\t" 
		<< get_random(current)/double(m-1) << "\t" << std::endl;
	}
	return 0;
}