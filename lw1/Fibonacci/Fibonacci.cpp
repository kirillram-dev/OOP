#include <iostream>
#include <algorithm>
#include <vector>


size_t Fib(std::vector<size_t>& fib, const size_t n)
{
	if (n == 1 || n == 0)
	{
		fib[1] = 1;
		return n;
	}
	else
	{
		if (fib[n] != 0)
		{
			return fib[n];
		}
		else
		{
			fib[n] = Fib(fib, n - 1) + Fib(fib, n - 2);
			return fib[n];
		}
	}
}

bool CheckArgumentCount(const int argumentCount)
{
	if (argumentCount != 2)
	{
		std::cerr << "invalid params. Use this:" << std::endl;
		std::cerr << "Fibonacci <number>" << std::endl;
		return false;
	}
	return true;
}

bool IsNumber(const std::string& str)
{
	return std::all_of(str.begin(), str.end(), isdigit);
}

int main(int argc, char* argv[])
{
	if (!CheckArgumentCount(argc) || !IsNumber(argv[1]))
	{
		return 1;
	}

	size_t n = atoi(argv[1]);

	std::vector<size_t> fib(n + 1, 0);

	std::cout << Fib(fib, n) << std::endl;
}
