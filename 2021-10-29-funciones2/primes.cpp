#include<iostream>
#include<cmath>

static int isPrime(long int n);
long int greatestPrimeDivisor(long int n);
long int sumOfPrimesfactors(long int n);

int main(int argc, char const *argv[])
{
	long int const N = 600851475147;
	//long int const N = 21;
	std::cout << "suma_de_divisores_primos(" << N << ") = " << sumOfPrimesfactors(N) << std::endl;
	return 0;
}


static int isPrime(long int n)
{
	for(long int y = 2; y <= sqrt(n); y++)
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

long int sumOfPrimesfactors(long int n)
{
	long int sum = -1;
	for(long int x = 1; x <= sqrt(n); x++)
	{
		if(!(n%x))
		{
			if(isPrime(x))
			{
				sum += x;
			}
			if(isPrime(n/x))
			{
							sum += n/x;
			}
		}
	}

	return sum;
}