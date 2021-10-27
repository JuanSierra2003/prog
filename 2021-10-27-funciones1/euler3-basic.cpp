#include<iostream>
#include<cmath>

static long int isPrime(long int n);
long int greatestPrimeDivisor(long int n);

int main(int argc, char const *argv[])
{
	long int const N = 600851475147;
	std::cout << "mayor_divisor_primo(" << N << ") = " << greatestPrimeDivisor(N) << std::endl;
	return 0;
}



static long int isPrime(long int n)
{
	for(long int y = 2; y < sqrt(n); y++)
	{
		if(!(n%y))
		{
			return 0;
		}
	}
	return 1;
}

long int greatestPrimeDivisor(long int n)
{
	for(long int x = 2; x <= sqrt(n); x++)  //Los divisores vienen en parejas,
	{							   			//el menor numero en una pareja puede
		if(!(n%x))						   //ser maximo la raiz cuadrada de N.
		{
			if(isPrime(n/x))
				{
					return n/x;
				}
		}
	}

	for(long int x = (int) sqrt(n); x > 0; x--)
	{
		if(!(n%x))
		{
			if(isPrime(x))
				{
					return x;
				}
		}

	}
	return 1;
}