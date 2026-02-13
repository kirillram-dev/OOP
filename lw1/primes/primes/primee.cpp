#include <iostream>
#include <vector>


int main()
{
	// моя первая программа
	
	std::vector<size_t> prim;
	for (size_t i = 0; i < 1000; i++)
	{
		prim.push_back(i);
	}
	
	for (size_t i = 2; i < 1000; i++)
	{
		if (prim[i] != 0)
		{
			size_t d = prim[i];
			for (size_t i = 2 * d; i < 100; i = i + d)
			{

				prim[i] = 0;
			}
		}
	}
	
	for (size_t i = 2; i < 1000; i++)
	{
		if (prim[i] != 0)
		{
			std::cout << prim[i] << " ";
		}
	}

	std::cout << std::endl;
	return 0;
} 