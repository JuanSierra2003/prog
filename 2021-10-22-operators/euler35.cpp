#include<iostream>

int main()
{
	const int div1 = 3, div2 = 5;
	const int limit = 1000;
	int sum = 0;

	for(int n = 1; n < limit; n++)
	{
		if((n%div1 == 0) || (n%div2 == 0))
		{
			sum += n;
		}
	}

	std::cout << sum << std::endl;

	return 0;
}