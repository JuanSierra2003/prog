#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<random>
#include<map>
#include<fstream>
#include<chrono>
#include<functional>


int main(int argc, char const *argv[])
{
	const int N = std::atoi(argv[1]);
	//crate and fill vector
	std::vector <int> V(N, 0.0);
	std::iota(V.begin(), V.end(), 10);
	//print vector
	std::cout << "V = (";
	std::for_each(V.begin(), V.end(), [](int n){std::cout << n << ", ";});
	std::cout << ")\n";
	//count numbers n: n>25
	std::cout << "count if n>25: " << std::count_if(V.begin(), V.end(), [](int n){return n > 25;}) << std::endl;
	//count numbers n: 3|n ^ 5|n 
	std::cout << "count if 3|n ^ 5|n: " << std::count_if(V.begin(), V.end(), [](int n){return !(n%15);}) << std::endl;
	//is there n: 7|n ^ 13|n
	bool tmp = std::count_if(V.begin(), V.end(), [](int n){return !(n%91);});
	std::cout << "is there n: 7|n ^ 13|n; " << tmp << std::endl;
	//sort vector bgy greater
	std::sort(V.begin(), V.end(), std::greater());
	//print sorted vector
	std::cout << "V sorted by std::greater() [0,9]  = (";
	std::for_each(V.begin(), V.begin() + 9, [](int n){std::cout << n << ", ";});
	std::cout << ")\n";

	//start clock
	auto start = std::chrono::steady_clock::now();
	//calculate mean
	std::cout << "mean: " << ((double) std::accumulate(V.begin(), V.end(), 0))/N << std::endl;
    //end clock
    auto end = std::chrono::steady_clock::now();
    //calculate duration
    std::chrono::duration<float,std::milli> duration = end - start;
    std::cout << "duration of calculation of mean : " << duration.count() << "s" << std::endl;

    //create hist
	std::mt19937 gen(5);
	std::normal_distribution <double> dis(0, 2);

	std::map <int, int> hist;
	
	for(int i = 0; i < 10000; i++)
	{
		hist[std::round(dis(gen))]++;
	}

	std::ofstream fout("histo.txt");
	fout.precision(15); fout.setf(std::ios::scientific);


	for(auto & x: hist)
	{
		fout << x.first << "\t" << x.second << std::endl;
	}

	return 0;
}

