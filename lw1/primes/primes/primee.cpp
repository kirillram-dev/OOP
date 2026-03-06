#include <iostream>
#include <vector>
#include <set>

#include "primesUtilites.h"

int main(int argc, char* argv[])
{
	

	const std::string upperBound = argv[1];



	std::set<size_t> primes = GeneratePrimeNumberSet(atoi(upperBound.c_str()));



	
	for (auto pr : primes)
	{
		std::cout << pr << " ";
	}

	return 0;
} 