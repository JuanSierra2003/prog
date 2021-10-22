#include<iostream>

int main()
{
	std::cout << ((5==5) && (3>6)) << std::endl;
	std::cout << ((5==5) || (3>6)) << std::endl;

	int flag = (5>4)? -1 : 32;
	std::cout << flag << std::endl;

	int m = 2, n = 17, k = 0;

	k = m & n;
	std::cout << k << std::endl;
	k = m | n;
	std::cout << k << std::endl;
	k = m << 2;
	std::cout << k << std::endl;
	k = m >> 2;
	std::cout << k << std::endl;
	
	return 0;
}