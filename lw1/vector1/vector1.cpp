#include <iostream>
#include <vector>
#include <iterator>

std::vector<double> GetNumbers(std::istream& input) 
{
	return { std::istream_iterator<double>(input), std::istream_iterator<double>() };
}

void VectorConversion(std::vector<double>& numbers)
{
	if (numbers.empty())
	{
		return;
	}
}

void process(std::vector<double>& numbers) 
{
	double sum = 0.0;
	size_t count = 0;
	for (size_t i = 0; i < numbers.size(); i++) 
	{
		if (numbers[i] > 0) 
		{
			sum += numbers[i]; 
			count++;
		}
	}
	
	double avg = sum / count;

	if (avg <= DBL_EPSILON)
	{
		return;
	}

	for (size_t i = 0; i < numbers.size(); i++) 
	{
		numbers[i] = numbers[i] + avg;
	}
}

void print(const std::vector<double>& a) 
{
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << ' ';
	}
}

int main()
{
	std::vector<double> numbers = GetNumbers(std::cin);
	process(numbers);
	copy(numbers.begin(), numbers.end(), std::ostream_iterator<size_t>(std::cout, " "));
	return 0;
}

