#include <iostream>
#include <cmath>

long int greatestDivisor(long int n)
{
	for(long int x = 2; x <= sqrt(n); x++)
	{
		if(!(n%x))
		{
			return n/x;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	long int const N = 600851475147;
	std::cout << "mayor_divisor(" << N << ") = " << greatestDivisor(N) << std::endl; 
	return 0;
}