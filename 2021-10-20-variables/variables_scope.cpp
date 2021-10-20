#include<iostream>

int a = 8;

int main()
{
	std::cout << a << "\n";
	std::cout << &a << "\n\a";

	int a = 9;
	std::cout << a << "\n";
	std::cout << &a << "\n\a";
	std::cout << ::a << "\n";
	std::cout << &::a << "\n\a";

	{
		int a = 10;
		std::cout << a << "\n";
		std::cout << &a << "\n\a";
	}
		return 0;
}