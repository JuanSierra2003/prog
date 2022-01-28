#include<iostream>
#include<random>
#include<map>

const int SEED = 1;
const int N = 1000;

int main(int argc, char const *argv[])
{
	std::mt19937 engine(SEED);
	std::uniform_real_distribution<double> gen(-2, 2);

	std::map<int, int> hist;

	for(int iter = 0; iter < N; iter++){
		hist[(int)(gen(engine)+2)]++;
	}

	for(auto p: hist){
		std::cout << p.first - 1.5 << "\t" << double(p.second)/N << "\n";
	}

	return 0;
}