#include "primesUtilites.h"




std::set<size_t> GeneratePrimeNumberSet(const size_t upperBound)
{
	std::vector<bool> isPrimes(upperBound + 1, true);

	for (size_t i = 3; i * i < upperBound + 1; i++)
	{
		for (size_t j = i * i; j < upperBound + 1; j = j + 2 * i)
		{
			isPrimes[j] = false;
		}
	}

	std::set<size_t> primes;
	primes.emplace_hint(primes.end(), 2);

	for (size_t i = 3; i < upperBound + 1; i = i + 2)
	{
		if (isPrimes[i])
		{
			primes.emplace_hint(primes.end(), i);
		}
	}
	return primes;
}