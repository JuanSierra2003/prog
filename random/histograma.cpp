#include<iostream>
#include<random>

int main(int argc, char const *argv[])
{
	const long int N = std::atoi(argv[1]);
	const double Seed = std::atof(argv[2]);


	std::mt19937 gen(Seed);
	std::normal_distribution <double> dis(0, 1);

	
	long int inter = N/1000;
	double hist[inter + 2]{0};

	for(long int i = 0; i < N; i++)
	{
		hist[(int)((dis(gen)+3.0)/(6.0/inter))] += 1;
	}

	for(long int i = 0; i<inter; i++)
	{
		std::cout << (6.0/inter)*(i+0.5)-3 << " " << hist[i] << "\n";
	}

	return 0;
}