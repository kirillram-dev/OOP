
#include <iostream>
#include <algorithm>

size_t Factorial(const size_t n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

bool CheckArgumentCount(const int argumentCount)
{
	if (argumentCount != 2)
	{
		std::cerr << "invalid params. Use this:" << std::endl;
		std::cerr << "factorial <number>" << std::endl;
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

	std::cout << Factorial(n) << std::endl;
}
